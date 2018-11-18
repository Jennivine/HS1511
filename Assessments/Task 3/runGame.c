#include "Game.h"
#include <stdio.h>
#include <stdlib.h>

int getWinningPlayer(Game g);
int gameNotOver(Game g);
void printStudentTypes(void);

#define VERTEX_INFO 8
#define ARC_INFO 9
#define KPI_PER_UNI 10
#define ARC_PER_UNI 11
#define NORMAL_CAM_PER_UNI 12
#define GO8_CAM_PER_UNI 13
#define IP_PER_UNI 14
#define PUB_PER_UNI 15
#define TYPE_OF_STUD_PER_UNI 16
#define EXCHANGE_RATE_INFO 17


int main(int argv, char* argc[]){
    
    int i=0; //counter to keep track of user input of discipline and dice
    printf("Welcome to the university simulator\n");
    printf("Please enter the student type and dice number\n");
    printf("for each region\n");
    
    int discipline[NUM_REGIONS];
    int dice[NUM_REGIONS];
    
    while(i<NUM_REGIONS){
        scanf("%d %d\n", &(discipline[i]), &(dice[i]));
        i++;
    }
    printf("thank you!");
    
    //starting a new game
    Game g = newGame (discipline, dice);
    action action;
    int actionCode;
    int diceNumber;
    
    while(gameNotOver(g)){
        printf("Please roll a pair of dice and enter their sum.");
        scanf("%d", &diceNumber);
        while((diceNumber < 1) || (diceNumber > 12)){
            printf("Nice try. ");
            printf("Please roll a PAIR of dice and enter their sum.\n");
            scanf("%d", &diceNumber);
        }
        throwDice (g, diceNumber); //throwing the dice updates the resource on board and progresses the turn by 1
        
        printf("it is now Player %d's turn\n", getWhoseTurn (g));
        printf("Please choose from the following actions\n");
        
        printf("Option %d PASS\n", PASS);
        printf("Option %d BUILD_CAMPUS\n", BUILD_CAMPUS);
        printf("Option %d BUILD_GO8\n", BUILD_GO8);
        printf("Option %d OBTAIN_ARC\n", OBTAIN_ARC);
        printf("Option %d START_SPINOFF\n", START_SPINOFF);
        printf("Option %d RETRAIN_STUDENTS\n", RETRAIN_STUDENTS);
        
        printf("Option %d obtain info about a vertex\n", VERTEX_INFO);
        printf("Option %d obtain info about an ARC grant\n", ARC_INFO);
        printf("Option %d obtain info about how many KPIs a player has\n", KPI_PER_UNI);
        printf("Option %d obtain info about how many ARCs a player has\n", ARC_PER_UNI);
        printf("Option %d obtain info about how many Normal campuses a player has\n", NORMAL_CAM_PER_UNI);
        printf("Option %d obtain info about how many GO8 campuses a player has\n", GO8_CAM_PER_UNI);
        printf("Option %d obtain info about how many IPs a player has\n", IP_PER_UNI);
        printf("Option %d obtain info about how many Publications a player has\n", PUB_PER_UNI);
        printf("Option %d obtain info about how many students (of a certain type) a player has\n", TYPE_OF_STUD_PER_UNI);
        printf("Option %d obtain info about the current Exchange for retraining Students\n", EXCHANGE_RATE_INFO);
        
        scanf("%d\n", &actionCode);
        
        while(actionCode != PASS){
            if (actionCode ==  BUILD_CAMPUS){
                printf("Please enter a path to where you wish to place your campus\n");
                scanf("%149s\n", action.destination);
                action.actionCode = actionCode;
                if(isLegalAction (g, action)){
                    makeAction (g, action);
                    printf("You have successfully built a campus\n");
                } else {
                    printf("It is not legal for you to build this campus\n");
                }
                
            } else if (actionCode == BUILD_GO8) {
                printf("Please enter a path to where you wish to place your GO8 Campus\n");
                scanf("%149s\n", action.destination);
                action.actionCode = actionCode;
                if(isLegalAction (g, action)){
                    makeAction (g, action);
                    printf("You have successfully built a GO8 campus\n");
                } else {
                    printf("It is not legal for you to build this GO8 Campus\n");
                }
                
            } else if (actionCode == OBTAIN_ARC) {
                printf("Please enter a path to where you wish to place your ARC\n");
                scanf("%149s\n", action.destination);
                action.actionCode = actionCode;
                if(isLegalAction (g, action)){
                    makeAction (g, action);
                    printf("You have successfully obtained an ARC grant\n");
                } else {
                    printf("It is not legal for you to build this ARC\n");
                }
                
            } else if (actionCode == START_SPINOFF) {
                printf("Please roll a die and enter the value here\n");
                scanf("%d", &diceNumber);
                
                if(diceNumber%3 == 0){
                    action.actionCode = OBTAIN_IP_PATENT;
                    if(isLegalAction(g, action)){
                        makeAction(g, action);
                        printf("You have successfully obtained some useful IP\n");
                    } else {
                        printf("it is not legal for you to start a spinoff\n");
                    }
                } else {
                    action.actionCode = OBTAIN_PUBLICATION;
                    if(isLegalAction(g, action)){
                        makeAction(g, action);
                        printf("You have successfully obtained a Publication\n");
                    } else {
                        printf("it is not legal for you to start a spinoff\n");
                    }
                }
                
            } else if (actionCode == RETRAIN_STUDENTS) {
                action.actionCode = RETRAIN_STUDENTS;
                printf("Please Choose what type of student you wish retrain\n");
                printStudentTypes();
                scanf("%d", &(action.disciplineFrom));
                
                printf("Please Choose what type of stydent you want become\n");
                printStudentTypes();
                scanf("%d", &(action.disciplineTo));
                
                if(isLegalAction(g, action)){
                    makeAction(g, action);
                    printf("You have successfully retrained these students\n");
                } else {
                    printf("it is not legal for you to retrain these students. Sorry\n");
                }
                
            } else if (actionCode == VERTEX_INFO){
                //checks the state of a vertex of a certain path given
                printf("Please enter a path to where you wish to know about\n");
                scanf("%149s\n", action.destination);
                int vertex = getCampus(g, action.destination);
                printf("the vertex type of this path is %d \n", vertex);
                
            } else if (actionCode == ARC_INFO){
                //checks te state of an ARC of a certain path given
                printf("Please enter a path to where you wish to know about\n");
                scanf("%149s\n", action.destination);
                int vertex = getARC(g, action.destination);
                printf("the ARC Type of this path is %d \n", vertex);
                
            } else if (actionCode == KPI_PER_UNI){
                //gets the amount of KPI points a given Uni (player) has
                printf("Please enter the UNI about whome you wish to find out about\n");
                int player;
                scanf("%d", &player);
                
                printf("This Uni has %d KPIs\n", getKPIpoints(g, player));
                
            } else if (actionCode == ARC_PER_UNI){
                //gets the amount of ARC grants a given Uni (player) has
                printf("Please enter the UNI about whome you whish to find out about\n");
                int player;
                scanf("%d", &player);
                
                printf("This Uni has %d ARCs\n", getARCs(g, player));
                
            } else if (actionCode == NORMAL_CAM_PER_UNI){
                //gets the number of normal campuses a given Uni (player) has
                printf("Please enter the UNI about whome you wish to find out about\n");
                int player;
                scanf("%d", &player);
                
                printf("This Uni has %d Campuses\n", getCampuses(g, player));
                
            } else if (actionCode == GO8_CAM_PER_UNI){
                //gets the number of GO8 campuses a given Uni (player) has
                printf("Please enter the UNI about whome you wish to find out about\n");
                int player;
                scanf("%d", &player);
                
                printf("This Uni has %d GO8s\n", getGO8s(g, player));
                
            } else if (actionCode == IP_PER_UNI){
                //gets the number of IPs a given Uni (player) has
                printf("Please enter the UNI about whome you wish to find out about\n");
                int player;
                scanf("%d", &player);
                
                printf("This Uni has %d IPs\n", getIPs(g, player));
                
            } else if (actionCode == PUB_PER_UNI){
                //gets the number of publications a given Uni (player) has
                printf("Please enter the UNI about whome you wish to find out about\n");
                int player;
                scanf("%d", &player);
                
                printf("This Uni has %d Publications\n", getPublications(g, player));
                
            } else if (actionCode == TYPE_OF_STUD_PER_UNI){
                //gets the number of a specified type of student a given Uni (player) has
                printf("Please enter the UNI about whome you wish to find out about\n");
                int player;
                scanf("%d", &player);
                
                printf("Please choose the Student type about which you wish to find out about\n ");
                printStudentTypes();
                int studentType;
                scanf("%d", &studentType);
                
                printf("This Uni has %d student of this type\n",
                       getStudents (g, player, studentType));
                
            } else if (actionCode == EXCHANGE_RATE_INFO){
                //gets the exchange rate between students a given Uni (player) can enjoy
                printf("Please enter the UNI about whome you wish to find out about\n");
                int player;
                scanf("%d", &player);
                
                printf("Please choose what type of student you wish to find out about retraining from\n");
                printStudentTypes();
                scanf("%d", &(action.disciplineFrom));
                
                printf("Please choose what type of stydent you want to find out about retraining to\n");
                printStudentTypes();
                scanf("%d", &(action.disciplineTo));
                
                printf("This Retrianing has a cost of %d per student\n",
                       getExchangeRate (g, player,
                                        action.disciplineFrom, action.disciplineTo));
            } else {
                printf("Please Choose a valid Action");
            }
            
            printf("Please choose from the following actions\n");
            printf("Option %d PASS\n", PASS);
            printf("Option %d BUILD_CAMPUS\n", BUILD_CAMPUS);
            printf("Option %d BUILD_GO8\n", BUILD_GO8);
            printf("Option %d OBTAIN_ARC\n", OBTAIN_ARC);
            printf("Option %d START_SPINOFF\n", START_SPINOFF);
            printf("Option %d RETRAIN_STUDENTS\n", RETRAIN_STUDENTS);
            scanf("%d\n", &actionCode);
        }
    }
    
    printf("the game is over UNI %d wins", getWinningPlayer(g));
    disposeGame (g);
    return EXIT_SUCCESS;
}

int gameNotOver(Game g){
    int returnValue = TRUE;
    if (getKPIpoints(g, UNI_A) >= 150){
        returnValue = FALSE;
    }
    if (getKPIpoints(g, UNI_B) >= 150){
        returnValue = FALSE;
    }
    if (getKPIpoints(g, UNI_C) >= 150){
        returnValue = FALSE;
    }
    return returnValue;
}

int getWinningPlayer(Game g){
    int returnValue;
    if (getKPIpoints(g, UNI_A) >= 150){
        returnValue = UNI_A;
    }
    if (getKPIpoints(g, UNI_B) >= 150){
        returnValue = UNI_B;
    }
    if (getKPIpoints(g, UNI_C) >= 150){
        returnValue = UNI_C;
    }
    return returnValue;
}

void printStudentTypes(void){
    printf("THD students are of type %d\n", STUDENT_THD);
    printf("BPS students are of type %d\n", STUDENT_BPS);
    printf("BQN students are of type %d\n", STUDENT_BQN);
    printf("MJ students are of type %d\n", STUDENT_MJ);
    printf("MTV students are of type %d\n", STUDENT_MTV);
    printf("M$ students are of type %d\n", STUDENT_MMONEY);
}
