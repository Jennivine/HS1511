//
//  Game.c
//  
//
//  Created by Taylyvine on 26/4/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Game.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}

#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

#define NUM_DISCIPLINES 6
#define NUM_VERTICES 54
#define NUM_EDGES 72

typedef int vertex;
typedef int edge;

typedef struct _region{
    int diceScore;
    int discipline;
} region;

//static functions for isLegalAction
static int isLegalToBuildCampus(Game g, path destination);
static int isLegalToBuildGO8(Game g, path destination);
static int isLegalToObtainArc(Game g, path destination);
static int isLegalToStartSpinoff(Game g);
static int isLegalToRetrainStudents(Game g, int disciplineFrom, int disciplineTo);

static int isValidArcLocationForPlayer(Game g, path destination);
static int isEdgeAdjacentToMyCampus(Game g, path destination);
static int isEdgeAdjacentToMyEdge(Game g, path destination);
static int isVertexAdjacentToCampus(Game g, path destination);
static int isVertexAdjacentToMyArc(Game g, path destination);
static int numGO8s(Game g);
static int playerHasResources(Game g, int studentsNeeded[]);
static int isLegalPath(path pathToCheck);

typedef struct _board {
    vertex vertexes[11][11];
    edge edges[22][22];
    region regions[11][11];
} board;

typedef struct _board *Board;

typedef struct _player {
    int ARCs;
    int campuses;
    int GO8s;
    int publications;
    int patents;
    int KPI;
    
    int exchangeRate[NUM_DISCIPLINES][NUM_DISCIPLINES];
    int students[NUM_DISCIPLINES]; //each player (uni) has 6 types of student it can get
} player;

typedef struct _game {
    int currentTurn;
    int mostARCs;
    int mostPublications;
    player players[NUM_UNIS+1];
    Board gameBoard;
    int discipline[NUM_REGIONS]; //input argument from newGame function
    int dice[NUM_REGIONS]; //input argument from newGame function
} game;

Game newGame (int discipline[], int dice[]);

void disposeGame (Game g){
    //jennivine
    assert (g != NULL);
    assert (g->gameBoard != NULL);
    free (g->gameBoard);
    free (g);
}

void makeAction (Game g, action a);

void throwDice (Game g, int diceScore);

int getDiscipline (Game g, int regionID){
    return (g->discipline[regionID]);
}

int getDiceValue (Game g, int regionID){
    //jennivine
    return (g->dice[regionID]);
}

int getMostARCs (Game g){
    //jennivine
    assert(g != NULL);
    return (g->mostARCs);
}

int getMostPublications (Game g);

int getTurnNumber (Game g);

int getWhoseTurn (Game g){
    // jennivine
    int whoseTurn;
    assert(g != NULL);
    if (g->currentTurn < 0){
        whoseTurn = NO_ONE;
    } else {
        whoseTurn = (g->currentTurn % NUM_UNIS) + 1;
    }
    return whoseTurn;
}

int getCampus(Game g, path pathToVertex);

int getARC(Game g, path pathToEdge);

int isLegalAction (Game g, action a){
    //jennivine
    int returnValue;
    if(getTurnNumber(g) == -1){
        returnValue = FALSE;
    } else {
        if (a.actionCode == PASS){
            returnValue = TRUE;
        } else if (a.actionCode == BUILD_CAMPUS){
            returnValue = isLegalToBuildCampus(g, a.destination);
        } else if (a.actionCode == BUILD_GO8){
            returnValue = isLegalToBuildGO8(g, a.destination);
        } else if (a.actionCode == OBTAIN_ARC){
            returnValue = isLegalToObtainArc(g, a.destination);
        } else if (a.actionCode == START_SPINOFF){
            returnValue = isLegalToStartSpinoff(g);
        } else if (a.actionCode == OBTAIN_PUBLICATION){
            returnValue = FALSE;
        } else if (a.actionCode == OBTAIN_IP_PATENT){
            returnValue = FALSE;
        } else if (a.actionCode == RETRAIN_STUDENTS){
            returnValue =  isLegalToRetrainStudents(g, a.disciplineFrom, a.disciplineTo);
        } else {
            returnValue = FALSE;
        }
    }
    return returnValue;
}

int getKPIpoints (Game g, int player);

int getARCs (Game g, int player);

int getGO8s (Game g, int player);

int getCampuses (Game g, int player);

int getIPs (Game g, int player);

int getPublications (Game g, int player){
    //jennivine
    assert ((player > NO_ONE) && (player <= UNI_C));
    assert (g != NULL);
    return (g->players[player].publications);
}

int getStudents (Game g, int player, int discipline);

int getExchangeRate (Game g, int player, int disciplineFrom, int disciplineTo);

// static (helper) functions below
static int isLegalToBuildCampus(Game g, path destination){
    int returnValue = TRUE;
    int resourcesToBuildCampus[NUM_DISCIPLINES] = {0, 1, 1, 1, 1, 0};
    if(isLegalPath(destination) == FALSE){
        //path given is not legal
        //therefore cannot build campus
        returnValue = FALSE;
    } else {
        if(!((getCampus(g, destination) == VACANT_VERTEX))){
            //Destination is not vacant
            //therefore cannot build campus
            returnValue = FALSE;
        }
        if(!(playerHasResources(g, resourcesToBuildCampus))){
            //player doesn't have required resource
            //therefore cannot build campus
            returnValue = FALSE;
        }
        if(!(isVertexAdjacentToMyArc(g, destination))){
            //campus can only be built if it's connected to an ARC grant
            //therefore cannot build campus
            returnValue = FALSE;
        }
        if(isVertexAdjacentToCampus(g, destination)){
            //campus cannot be built adjacent to another one
            //therefore cannot build campus
            returnValue = FALSE;
        }
    }
    return returnValue;
}

static int isLegalToBuildGO8(Game g, path destination){
    int returnValue = TRUE;
    int resourcesToBuildGO8[NUM_DISCIPLINES] = {0, 0, 0, 2, 0, 3};
    if(!isLegalPath(destination)){
        //path given is not legal
        //therefore cannot build GO8 campus
        returnValue = FALSE;
    } else {
        if(!(getCampus(g, destination) == getWhoseTurn(g))){
            //player is trying to convert someone else's campus or campus is already GO8
            //therefore cannot build GO8 campus
            returnValue = FALSE;
        }
        if(!playerHasResources(g, resourcesToBuildGO8)){
            //player doesn't have required resource
            //therefore cannot build GO8 campus
            returnValue = FALSE;
        }
        if(!(numGO8s(g) < 8)){
            //number of GO8 campus exceeds maximum 8
            //therefore cannot build GO8 campus
            returnValue = FALSE;
        }
    }
    return returnValue;
}

static int isLegalToObtainArc(Game g, path destination){
    int returnValue = TRUE;
    int resourcesToObtainARC[NUM_DISCIPLINES] = {0, 1, 1, 0, 0, 0};
    if(!isLegalPath(destination)){
        //path given is not legal
        //therefore cannot obtain ARC
        returnValue = FALSE;
    } else {
        if(!(getARC(g, destination) == VACANT_ARC)){
            //ARC destination is already occupied
            //therefore cannot obtain ARC
            returnValue = FALSE;
        }
        if(!playerHasResources(g, resourcesToObtainARC)){
            //player doesn't have required resource
            //therefore cannot obtain ARC
            returnValue = FALSE;
        }
        if(!isValidArcLocationForPlayer(g, destination)){
            //ARC can only be built only the edge of hexagons
            //therefore cannot obtain ARC
            returnValue = FALSE;
        }
    }
    return returnValue;
}

static int isLegalToStartSpinoff(Game g){
    int returnValue = TRUE;
    int resourcesToStartSpinoff[NUM_DISCIPLINES] = {0, 0, 0, 1, 1, 1};
    if(!playerHasResources(g, resourcesToStartSpinoff)){
        //player doesn't have required resource
        //therefore cannot start a spinoff
        returnValue = FALSE;
    }
    return returnValue;
}

static int isLegalToRetrainStudents(Game g, int disciplineFrom, int disciplineTo){
    int returnValue = TRUE;
    if (disciplineFrom == disciplineTo){
        //cannot retrain student to and from the same type
        returnValue = FALSE;
    }
    if (disciplineFrom == STUDENT_THD){
        //THD students cannot be retrained
        returnValue = FALSE;
    }
    if (getStudents (g,getWhoseTurn(g), disciplineFrom) <
        getExchangeRate(g, getWhoseTurn(g), disciplineFrom, disciplineTo)){
        //not enough students of type 'disciplineFrom' to proceed the retraining
        //therefore cannot retrain students
        returnValue = FALSE;
    }
    return returnValue;
}

static int numGO8s(Game g){
    int returnValue = 0;
    int i = 0;
    while (i < NUM_UNIS){
        returnValue += getGO8s (g, i);
        i++;
    }
    return returnValue;
}

static int playerHasResources(Game g, int studentsNeeded[]){
    int returnValue = TRUE;
    int discipline = 0;
    int player = getWhoseTurn(g);
    while (discipline < NUM_DISCIPLINES){
        if(getStudents (g, player, discipline) < studentsNeeded[discipline]){
            returnValue = FALSE;
        }
        discipline++;
    }
    return returnValue;
}

static int isLegalPath(path pathToCheck){ //incomplete
    int returnValue = TRUE;
    path tempPath;
    int lengthOfPath = (int)strlen (pathToCheck);
    strcpy (tempPath, pathToCheck);
    tempPath[lengthOfPath - 1] = '\0';
    if (lengthOfPath == 0){
        returnValue = TRUE;
    } else {
        returnValue = (isLegalPath(tempPath));
    }
    return returnValue;
}

static int isVertexAdjacentToCampus(Game g, path destination){
    int returnValue = FALSE;
    path tempPath;
    int length = (int)strlen (destination);
    strcpy (tempPath, destination);
    tempPath[length] = '\0';
    tempPath[length - 1] = 'R';
    if(getCampus(g, tempPath) != VACANT_VERTEX){
        returnValue = TRUE;
    }
    tempPath[length - 1] = 'L';
    if(getCampus(g, tempPath) != VACANT_VERTEX){
        returnValue = TRUE;
    }
    if(getCampus(g, tempPath) != VACANT_VERTEX){
        returnValue = TRUE;
    }
    return returnValue;
}

static int isVertexAdjacentToMyArc(Game g, path destination){
    int returnValue = FALSE;
    path tempPath;
    int player = getWhoseTurn(g);
    int myARC  = player + 1;
    int length = (int)strlen (destination);
    strcpy (tempPath, destination);
    tempPath[length] = '\0';
    tempPath[length - 1] = 'R';
    if(getARC(g, tempPath) == myARC){
        returnValue = TRUE;
    }
    tempPath[length - 1] = 'L';
    if(getARC(g, tempPath) == myARC){
        returnValue = TRUE;
    }
    tempPath[length - 1] = 'B';
    if(getARC(g, tempPath) == myARC){
        returnValue = TRUE;
    }
    return returnValue;
}

static int isValidArcLocationForPlayer(Game g, path destination){
    int returnValue = FALSE;
    if (isEdgeAdjacentToMyCampus(g, destination)){
        returnValue = TRUE;
    }
    if (isEdgeAdjacentToMyEdge(g, destination)){
        returnValue = TRUE;
    }
    return returnValue;
}

static int isEdgeAdjacentToMyCampus(Game g, path destination){
    path tempPath;
    int returnValue = FALSE;
    int player = getWhoseTurn(g);
    int myCampus  = player;
    int length = (int) strlen (destination);
    strcpy (tempPath, destination);
    tempPath[length] = '\0';
    tempPath[length - 1] = 'B';
    if(getCampus(g, tempPath) == myCampus){
        returnValue = TRUE;
    }
    if(getCampus(g, destination) == myCampus){
        returnValue = TRUE;
    }
    return returnValue;
}

static int isEdgeAdjacentToMyEdge(Game g, path destination){
    printf("%s\n", destination);
    int returnValue = FALSE;
    path tempPath;
    int player = getWhoseTurn(g);
    int myARC  = player;
    int length = (int)strlen (destination);
    strcpy (tempPath, destination);
    tempPath[length + 1] = '\0';
    tempPath[length] = 'R';
    if(getARC(g, tempPath) == myARC){
        returnValue = TRUE;
    }
    tempPath[length] = 'L';
    if(getARC(g, tempPath) == myARC){
        returnValue = TRUE;
    }
    tempPath[length] = 'B';
    tempPath[length + 2] = '\0';
    tempPath[length + 1] = 'R';
    if(getARC(g, tempPath) == myARC){
        returnValue = TRUE;
    }
    tempPath[length + 1] = 'L';
    if(getARC(g, tempPath) == myARC){
        returnValue = TRUE;
    }
    return returnValue;
}
