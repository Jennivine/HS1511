//
//  testGame.c
//
//
//  Created by taylyvine on 26/4/18.
//     testing each function just assumes the action is legal to perform
//
 
#include "Game.h"
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
 
#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
 
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,3,8,10,5}
 
#define B_START "LRLRLRRLRL"
#define C_START "RRLRLLRLRL"
 
void test_newGame (void);
void test_Action (void);
void test_throwDice (void);
void test_getDiscipline (void);
void test_getDiceValue (void);
void test_getMostARCs (void);
void test_getMostPublications (void);
void test_getTurnNumber (void);
void test_getWhoseTurn (void);
void test_getCampus (void);
void test_getARC (void);
void test_isLegalAction (void);
void test_getKPIpoints (void);
void test_getARCs (void);
void test_getGO8s (void);
void test_getCampuses (void);
void test_getIPs (void);
void test_getPublications (void);
void test_getStudents (void);
void test_getExchangeRate (void);
 
int main (int argc, char *argv[]){
    test_newGame();
    //test_makeAction();
    test_throwDice();
    test_getDiscipline();
    test_getDiceValue();
    test_getMostARCs();
    test_getMostPublications();
    test_getTurnNumber();
    test_getWhoseTurn();
    test_getCampus();
    test_getARC();
    test_isLegalAction();
    test_getKPIpoints();
    test_getARCs();
    test_getGO8s();
    test_getCampuses();
    test_getIPs();
    test_getPublications();
    test_getStudents();
    test_getExchangeRate();
    
    //At the end, if you have passed all the tests, printf "All tests passed, you are Awesome!".
    printf("All tests passed, you are Awesome");
    return EXIT_SUCCESS;
}
 
void test_newGame (void) {
    // Lily
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    //state of Terra Nullis
    //test that the current turn number/player is correct
    assert(getTurnNumber(g) == -1);
    assert(getWhoseTurn(g) == NO_ONE);
    
    //test no unis have most arcs or publications
    assert(getMostARCs(g) == NO_ONE);
    assert(getMostPublications(g) == NO_ONE);
    
    //test all unis have 2o KPI points
    assert(getKPIpoints(g, UNI_A) == 20);
    assert(getKPIpoints(g, UNI_B) == 20);
    assert(getKPIpoints(g, UNI_C) == 20);
    
    //test unis have 0 arcs
    assert(getARCs(g, UNI_A) == 0);
    assert(getARCs(g, UNI_B) == 0);
    assert(getARCs(g, UNI_C) == 0);
    
    //test unis have 0 G08s
    assert(getGO8s(g, UNI_A) == 0);
    assert(getGO8s(g, UNI_B) == 0);
    assert(getGO8s(g, UNI_C) == 0);
    
    //test unis have 2 campuses
    assert(getCampuses(g, UNI_A) == 2);
    assert(getCampuses(g, UNI_B) == 2);
    assert(getCampuses(g, UNI_C) == 2);
    
    //test unis have 0 IPs
    assert(getIPs(g, UNI_A) == 0);
    assert(getIPs(g, UNI_B) == 0);
    assert(getIPs(g, UNI_C) == 0);
    
    //test unis have 0 publications
    assert(getPublications(g, UNI_A) == 0);
    assert(getPublications(g, UNI_B) == 0);
    assert(getPublications(g, UNI_C) == 0);
    
    //test unis have 3xBPS, 3 x B?, 1 x MTV, 1 x MJ, 1 x M$, and no ThD students
    assert(getStudents(g, UNI_A, STUDENT_BPS) == 3);
    assert(getStudents(g, UNI_B, STUDENT_BPS) == 3);
    assert(getStudents(g, UNI_C, STUDENT_BPS) == 3);
    
    assert(getStudents(g, UNI_A, STUDENT_BQN) == 3);
    assert(getStudents(g, UNI_B, STUDENT_BQN) == 3);
    assert(getStudents(g, UNI_C, STUDENT_BQN) == 3);
    
    assert(getStudents(g, UNI_A, STUDENT_MTV) == 1);
    assert(getStudents(g, UNI_B, STUDENT_MTV) == 1);
    assert(getStudents(g, UNI_C, STUDENT_MTV) == 1);
    
    assert(getStudents(g, UNI_A, STUDENT_MJ) == 1);
    assert(getStudents(g, UNI_B, STUDENT_MJ) == 1);
    assert(getStudents(g, UNI_C, STUDENT_MJ) == 1);
    
    assert(getStudents(g, UNI_A, STUDENT_MMONEY) == 1);
    assert(getStudents(g, UNI_B, STUDENT_MMONEY) == 1);
    assert(getStudents(g, UNI_C, STUDENT_MMONEY) == 1);
    
    assert(getStudents(g, UNI_A, STUDENT_THD) == 0);
    assert(getStudents(g, UNI_B, STUDENT_THD) == 0);
    assert(getStudents(g, UNI_C, STUDENT_THD) == 0);
    
    disposeGame(g);
}
 
void test_makeAction (void){
    //Tay
    //checks the resources used gets reduced.
    //checks the action is actually made.
}
 
void test_throwDice (void){
    //Done in Tute
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    //test that the turn progresses
    throwDice(g,2);
    assert( getWhoseTurn(g) == UNI_A);
    throwDice(g,2);
    assert( getWhoseTurn(g) == UNI_B);
    throwDice(g,2);
    assert( getWhoseTurn(g) == UNI_C);
    
    //test that the resources update
    throwDice(g,11);
    assert(getStudents(g, UNI_A, STUDENT_MTV) == 2);
    throwDice(g,9);
    assert(getStudents(g, UNI_B, STUDENT_BQN) == 4);
    throwDice(g,8);
    assert(getStudents(g, UNI_C, STUDENT_MTV) == 2);
    
    throwDice(g,7);
    assert(getStudents(g, UNI_A, STUDENT_THD) == 3);
    
    disposeGame(g);
}
 
 
void test_getDiscipline (void){
    //Jennivine
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    assert (getDiscipline (g, 0)  == STUDENT_BQN);
    assert (getDiscipline (g, 1)  == STUDENT_MMONEY);
    assert (getDiscipline (g, 2)  == STUDENT_MJ);
    assert (getDiscipline (g, 3)  == STUDENT_MMONEY);
    assert (getDiscipline (g, 4)  == STUDENT_MJ);
    assert (getDiscipline (g, 5)  == STUDENT_BPS);
    assert (getDiscipline (g, 6)  == STUDENT_MTV);
    assert (getDiscipline (g, 7)  == STUDENT_MTV);
    assert (getDiscipline (g, 8)  == STUDENT_BPS);
    assert (getDiscipline (g, 9)  == STUDENT_MTV);
    assert (getDiscipline (g, 10) == STUDENT_BQN);
    assert (getDiscipline (g, 11) == STUDENT_MJ);
    assert (getDiscipline (g, 12) == STUDENT_BQN);
    assert (getDiscipline (g, 13) == STUDENT_THD);
    assert (getDiscipline (g, 14) == STUDENT_MJ);
    assert (getDiscipline (g, 15) == STUDENT_MMONEY);
    assert (getDiscipline (g, 16) == STUDENT_MTV);
    assert (getDiscipline (g, 17) == STUDENT_BQN);
    assert (getDiscipline (g, 18) == STUDENT_BPS);
    
    disposeGame(g);
}
 
void test_getDiceValue (void){
    //Jennivine
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    assert (getDiceValue (g, 0) == 9);
    assert (getDiceValue (g, 1) == 10);
    assert (getDiceValue (g, 2) == 8);
    assert (getDiceValue (g, 3) == 12);
    assert (getDiceValue (g, 4) == 6);
    assert (getDiceValue (g, 5) == 5);
    assert (getDiceValue (g, 6) == 3);
    assert (getDiceValue (g, 7) == 11);
    assert (getDiceValue (g, 8) == 3);
    assert (getDiceValue (g, 9) == 11);
    assert (getDiceValue (g, 10) == 4);
    assert (getDiceValue (g, 11) == 6);
    assert (getDiceValue (g, 12) == 4);
    assert (getDiceValue (g, 13) == 7);
    assert (getDiceValue (g, 14) == 9);
    assert (getDiceValue (g, 15) == 3);
    assert (getDiceValue (g, 16) == 8);
    assert (getDiceValue (g, 17) == 10);
    assert (getDiceValue (g, 18) == 5);
	
    
    disposeGame(g);
}
 
void test_getMostARCs (void){
    //Done in Tute
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    assert( getMostARCs(g) == NO_ONE);
    
    throwDice(g,2); //throw dice so UNI_A gets enough resources to build an ARC
    action test1;
    test1.actionCode = OBTAIN_ARC;
    strcpy(test1.destination,"R");
    makeAction(g,test1);
    
    assert( getMostARCs(g) == UNI_A);
    
    throwDice(g,2);
    
    //UNI_B obtains two arc in one throw
    
    action test2;
    test2.actionCode = OBTAIN_ARC;
    strcpy(test2.destination,"RRLRL");
    makeAction(g,test2);
    
    action test3;
    test3.actionCode = OBTAIN_ARC;
    strcpy(test3.destination,"RRLRLL");
    makeAction(g,test3);
    
    assert( getMostARCs(g) == UNI_B);
    disposeGame(g);
}
 
void test_getMostPublications (void){
    // Lily
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    // check no one has the most publications at first
    assert(getMostPublications(g) == NO_ONE);
    
    // check it is still no one after everyone has a go
    throwDice(g, 2);
    throwDice(g, 2);
    throwDice(g, 2);
    assert(getMostPublications(g) == NO_ONE);
    
    
    // check UNI_A has most publications after they gain one
    throwDice(g, 2);
    action test1;
    test1.actionCode = OBTAIN_PUBLICATION; //Starting a spinoff gives player 2/3 chance obtaining Publication
    makeAction(g,test1); //so calling it three times guarantees two publications obtained by UNI_A
    
    assert(getMostPublications(g) == UNI_A);
    
    // check UNI_A still has most after game play with no obtains
    throwDice(g, 2);
    throwDice(g, 2);
    assert(getMostPublications(g) == UNI_A);
    
    disposeGame(g);
}
 
void test_getTurnNumber (void){
    // LILY!!
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    // test initial turn number is -1
    assert(getTurnNumber(g) == -1);
    
    // test turn number increments with each roll
    throwDice(g, 2);
    assert(getTurnNumber(g) == 0);
    
    throwDice(g, 2);
    assert(getTurnNumber(g) == 1);
    
    throwDice(g, 2);
    assert(getTurnNumber(g) == 2);
    
    throwDice(g, 2);
    assert(getTurnNumber(g) == 3);
    
    throwDice(g, 2);
    assert(getTurnNumber(g) == 4);
    
    throwDice(g, 2);
    assert(getTurnNumber(g) == 5);
    
    throwDice(g, 2);
    assert(getTurnNumber(g) == 6);
    
    throwDice(g, 2);
    assert(getTurnNumber(g) == 7);
    
    throwDice(g, 2);
    assert(getTurnNumber(g) == 8);
    
    throwDice(g, 2);
    assert(getTurnNumber(g) == 9);
    
    disposeGame(g);
}
 
void test_getWhoseTurn (void){
    //Jennivine
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    //testing the state of "Terra Nullis"
    //where the dice is not thrown by anyone
    assert (getWhoseTurn(g)==NO_ONE);
    
    throwDice(g,2);
    assert (getWhoseTurn(g)==UNI_A);
    
    throwDice(g,2);
    assert (getWhoseTurn(g)==UNI_B);
    
    throwDice(g,2);
    assert (getWhoseTurn(g)==UNI_C);
    
    //test if the turn goes around back to UNI_A
    throwDice(g,2);
    assert (getWhoseTurn(g)==UNI_A);
    
    disposeGame(g);
}
 
void test_getCampus (void){
    //Tay????????????? but 98% Jennivine
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    
    //initially, most campuses are empty because no one has bought them
    assert(getCampus(g,"L") == VACANT_VERTEX);
    assert(getCampus(g,"LRRL") == VACANT_VERTEX);
    assert(getCampus(g,"RRLRLL") == VACANT_VERTEX);
    assert(getCampus(g,"RLLLLLBBRRRLRRLLLRLL") == VACANT_VERTEX);
    
    //initially, those given campuses belong to players already
    assert(getCampus(g,"RLLLLL") == CAMPUS_A);
    assert(getCampus(g,"RRLRL") == CAMPUS_B);
    assert(getCampus(g,"LRLRL") == CAMPUS_C);
    assert(getCampus(g,"RLRLRLRLRLL") == CAMPUS_A);
    assert(getCampus(g, B_START) == CAMPUS_B);
    assert(getCampus(g, C_START) == CAMPUS_C);
    
    //UNI_A's turn
    throwDice(g,2);
    //putting an ARC grant in edge 1
    action test1;
    test1.actionCode = OBTAIN_ARC;
    strcpy(test1.destination,"R");
    makeAction(g,test1);
    //extending the ARC grant
    action test2;
    test2.actionCode = OBTAIN_ARC;
    strcpy(test2.destination,"RL");
    makeAction(g,test2);
    //building a campus next to the ARC grant we just shoved in
    action test3;
    test3.actionCode = BUILD_CAMPUS;
    strcpy(test1.destination,"RL");
    makeAction(g,test3);
    
    //checking we just built the campus there at RL
    assert(getCampus(g,"RL") == CAMPUS_A);
    
    disposeGame(g);
}
 
void test_getARC (void){
    //Jennivine
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    
    //initially, all the arcs are vacant as no player received any ARC grant yet
    assert(getARC(g,"L") == VACANT_ARC);
    assert(getARC(g,"LRRL") == VACANT_ARC);
    assert(getARC(g,"RRLRLL") == VACANT_ARC);
    assert(getARC(g,"RLLLLLBBRRRLRRLLLRLL") == VACANT_ARC);
    
    //UNI_A places an ARC
    throwDice(g,2);
    
    action test1;
    test1.actionCode = OBTAIN_ARC;
    strcpy(test1.destination,"R");
    makeAction(g,test1);
    
    assert(getARC(g, "R") == ARC_A);
    
    //UNI_B places an ARC
    throwDice(g,2);
    
    action test2;
    test2.actionCode = OBTAIN_ARC;
    strcpy(test2.destination,"RRLRL");
    makeAction(g,test2);
    
    assert( getARC(g, "RRLRL") == ARC_B);
    
    //UNI_C places an ARC
    throwDice(g,2);
    
    action test3;
    test3.actionCode = OBTAIN_ARC;
    strcpy(test3.destination,"LRLRL");
    makeAction(g,test3);
    
    assert( getARC(g, "LRLRL") == ARC_C);
    
    disposeGame(g);
}
 
void test_isLegalAction (void){ //incomplete
    //Jennivine
    action testAction;
    
    // Create game:
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    
    //Currently at the state of Terra Nullis - no action should be legal
    int actionToTake = 0;
    while (actionToTake < 8){ //there is 8 different actions you can take
        testAction.actionCode = actionToTake;
        assert (isLegalAction(g, testAction) == FALSE);
        actionToTake ++;
    }
    
    // Advance from 'terra-nullis' where normal actions are legal.
    throwDice(g, 2);
    
    //individual player cannot obtain IP or Publication. Those can only be gained from business spinoff
    // Test OBTAIN_IP_PATENT
    testAction.actionCode = OBTAIN_IP_PATENT;
    assert (isLegalAction(g, testAction) == FALSE);
    
    // Test OBTAIN_PUBLICATION
    testAction.actionCode = OBTAIN_PUBLICATION;
    assert (isLegalAction(g, testAction) == FALSE);
    
    // Test that PASS is always allowed
    testAction.actionCode = PASS;
    assert (isLegalAction(g, testAction) == TRUE);
}
 
void test_getKPIpoints (void){
    //Tay
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    //all unis have 2 campuses, which are 10 points each
    assert(getKPIpoints(g,UNI_A) == 20);
    assert(getKPIpoints(g,UNI_B) == 20);
    assert(getKPIpoints(g,UNI_C) == 20);
    
    //UNI_A's turn
    throwDice(g,2);
    
    //putting an ARC grant in edge 1
    action test1;
    test1.actionCode = OBTAIN_ARC;
    strcpy(test1.destination,"R");
    makeAction(g,test1);
    //check points for 1 ARC and 2 campuses (ARC = 2 points)
    assert(getKPIpoints(g,UNI_A) == 22);
    
    //extending the ARC grant
    action test2;
    test2.actionCode = OBTAIN_ARC;
    strcpy(test2.destination,"RL");
    makeAction(g,test2);
    //check points for 2 ARCs and 2 campuses
    assert(getKPIpoints(g,UNI_A) == 24);
    
    //building a campus next to the ARC grant we just shoved in
    action test3;
    test3.actionCode = BUILD_CAMPUS;
    strcpy(test1.destination,"RL");
    makeAction(g,test3);
    //checking we have points for 2 ARCs and 3 campuses
    assert(getKPIpoints(g,UNI_A) == 34);
    
    disposeGame(g);
}
 
void test_getARCs (void){
    //Lily
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    // test 1: UNI_A gets an arc
    throwDice(g, 2);
    action test1;
    test1.actionCode = OBTAIN_ARC;
    strcpy(test1.destination,"R");
    makeAction(g, test1);
    assert(getARCs(g, UNI_A) == 1);
    
    // test 2: UNI_B gets an arc
    throwDice(g, 2);
    action test2;
    test2.actionCode = OBTAIN_ARC;
    strcpy(test1.destination,"RRLRL");
    makeAction(g, test2);
    assert(getARCs(g, UNI_B) == 1);
    
    // test 3: UNI_C gets an arc
    throwDice(g, 2);
    action test3;
    test3.actionCode = OBTAIN_ARC;
    strcpy(test3.destination,"LRLRL");
    makeAction(g, test3);
    assert(getARCs(g, UNI_C) == 1);
    
    // test 4: UNI_A gets a second arc
    throwDice(g, 2);
    action test4;
    test4.actionCode = OBTAIN_ARC;
    strcpy(test4.destination,"RL");
    makeAction(g, test4);
    assert(getARCs(g, UNI_A) == 2);
    
    // test 5: UNI_A gets a third arc
    throwDice(g, 2);
    throwDice(g, 2);
    throwDice(g, 2);
    action test5;
    test5.actionCode = OBTAIN_ARC;
    strcpy(test5.destination,"L");
    makeAction(g, test5);
    assert(getARCs(g, UNI_A) == 3);
    
    disposeGame(g);
}
 
void test_getGO8s (void){
    //Jennivine
    Game g = NULL;
    int i;
    
    // initialise game
    int disciplines[NUM_REGIONS];
    int dice[NUM_REGIONS];
    i = 0;
    while (i < NUM_REGIONS) {
        disciplines[i] = STUDENT_BPS; //Every region produces BPS studenst
        dice[i] = 6; //regions can only gains resource when 6 is throw
        i++;
    }
    
    // give everyone lots of resources
    i = 0;
    while (i < 3000) {
        // firstly give everyone lots of STUDENT_BPS
        throwDice(g, 6);
        i++;
    }
    
    // then retrain some of the STUDENT_BPS to other disciplines
    i = 0;
    while (i < 3) {
        throwDice(g, 6);
        int j = 0;
        while (j < 100) {
            action retrain = {RETRAIN_STUDENTS, "", STUDENT_BPS, -1 };
            
            retrain.disciplineTo = STUDENT_BQN;
            makeAction(g, retrain);
            retrain.disciplineTo = STUDENT_MJ;
            makeAction(g, retrain);
            retrain.disciplineTo = STUDENT_MTV;
            makeAction(g, retrain);
            retrain.disciplineTo = STUDENT_MMONEY;
            makeAction(g, retrain);
            j++;
        }
        i++;
    }
    
    // Terra Nullis condition
    // At the start, no one has any arcs
    assert(getGO8s (g, UNI_A) == 0);
    assert(getGO8s (g, UNI_B) == 0);
    assert(getGO8s (g, UNI_C) == 0);
    
    
    // Start with Player A's turn. Player A will make 2 arc grants and
    // build a campus
    throwDice(g, 6); {
        // Making first arc
        action makeARC = { OBTAIN_ARC, "L", 0 , 0 };
        makeAction(g, makeARC);
        // Second arc
        action makeSecondARC = { OBTAIN_ARC, "LR", 0 , 0 };
        makeAction(g, makeSecondARC);
        //built campus
        action buildCampus = { BUILD_CAMPUS, "LR", 0 , 0 };
        makeAction(g, buildCampus);
        assert(getGO8s (g, UNI_A) == 0);
        assert(getGO8s (g, UNI_B) == 0);
        assert(getGO8s (g, UNI_C) == 0);
        //convert campus to GO8
        action buildGO8 = { BUILD_GO8, "LR", 0 , 0 };
        makeAction(g, buildGO8);
        assert(getGO8s (g, UNI_A) == 1);
        assert(getGO8s (g, UNI_B) == 0);
        assert(getGO8s (g, UNI_C) == 0);	
	}
    
    // Now go to player B's turn. Player B will build 4 arcs, with a
    // campus at each secone one, and then convert them into GO8s
    // after creating each campus
    throwDice(g, 6); {
        // Making first arc
        action makeARC = { OBTAIN_ARC, B_START "B", 0 , 0 };
        makeAction(g, makeARC);
        // Second arc
        action makeSecondARC = { OBTAIN_ARC, B_START "BL", 0 , 0 };
        makeAction(g, makeSecondARC);
        // Building a campus
        action buildCampus = { BUILD_CAMPUS, B_START "BL", 0 , 0 };
        makeAction(g, buildCampus);
        assert(getGO8s (g, UNI_A) == 1);
        assert(getGO8s (g, UNI_B) == 0);
        assert(getGO8s (g, UNI_C) == 0);
        // Now converting it to GO8
        action buildGO8 = { BUILD_GO8, B_START "BL", 0 , 0 };
        makeAction(g, buildGO8);
        assert(getGO8s (g, UNI_A) == 1);
        assert(getGO8s (g, UNI_B) == 1);
        assert(getGO8s (g, UNI_C) == 0);
    
        // Making next 2 arcs
        action makeAnotherARC = { OBTAIN_ARC, B_START "BLR", 0 , 0 };
        makeAction(g, makeAnotherARC);
        // Second arc
        action makeLastARC = { OBTAIN_ARC, B_START "BLRL", 0 , 0 };
        makeAction(g, makeLastARC);
        //Building second campus
        action buildSecondCampus = { BUILD_CAMPUS, B_START "BLRL", 0 , 0 };
        makeAction(g, buildSecondCampus);
        assert(getGO8s (g, UNI_A) == 1);
        assert(getGO8s (g, UNI_B) == 1);
        assert(getGO8s (g, UNI_C) == 0);
        //converting second campus into G08
        action buildSecondGO8 = { BUILD_GO8, B_START "BLRL", 0 , 0 };
        makeAction(g, buildSecondGO8);
        assert(getGO8s (g, UNI_A) == 1);
        assert(getGO8s (g, UNI_B) == 2);
        assert(getGO8s (g, UNI_C) == 0);
	}
    
    // Now on to C's turn. C will make 3 arcs, and then a campus
    // then convert it to a GO8
    throwDice(g, 6); {
        // Making first arc
        action makeARC = { OBTAIN_ARC, C_START "L", 0 , 0 };
        makeAction(g, makeARC);
        // Second arc
        action makeSecondARC = { OBTAIN_ARC, C_START "LL", 0 , 0 };
        makeAction(g, makeSecondARC);
        // Build campus from arcs
        action buildCampus = { BUILD_CAMPUS, C_START "LL", 0 , 0 };
        makeAction(g, buildCampus);
        assert(getGO8s (g, UNI_A) == 1);
        assert(getGO8s (g, UNI_B) == 2);
        assert(getGO8s (g, UNI_C) == 0);
        // Convert campus to G08
        action buildGO8 = { BUILD_GO8, C_START "LL", 0 , 0 };
        makeAction(g, buildGO8);
        assert(getGO8s (g, UNI_A) == 1);
        assert(getGO8s (g, UNI_B) == 2);
        assert(getGO8s (g, UNI_C) == 1);
	}
    
    // Finally, converting A's primary campus into a GO8
    throwDice(g, 6);
        action convertGO8 = { BUILD_GO8, "", 0 , 0 };
        makeAction(g, convertGO8);
        assert(getGO8s (g, UNI_A) == 2);
        assert(getGO8s (g, UNI_B) == 2);
        assert(getGO8s (g, UNI_C) == 1);
    
    // That's all the tests
    disposeGame(g);
}
 
void test_getCampuses (void){
    //Lily
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame(disciplines, dice);
    
    // test UNI_A has 3 campuses after building one
    throwDice(g, 2);
    action test1;
    test1.actionCode = BUILD_CAMPUS;
    strcpy(test1.destination, "R");
    makeAction(g, test1);
    assert(getCampuses(g, UNI_A) == 3);
    
    // test UNI_B has 3 campuses after building one
    throwDice(g, 2);
    action test2;
    test2.actionCode = BUILD_CAMPUS;
    strcpy(test2.destination, "RRLRL");
    makeAction(g, test2);
    assert(getCampuses(g, UNI_B) == 3);
    
    // test values remain the same when no one builds
    throwDice(g, 2);
    throwDice(g, 2);
    throwDice(g, 2);
    assert(getCampuses(g, UNI_A) == 3);
    assert(getCampuses(g, UNI_B) == 3);
    assert(getCampuses(g, UNI_C) == 2);
    
    // test correct value changes when only one uni (UNI_C) gains
    throwDice(g, 2);
    action test3;
    test3.actionCode = BUILD_CAMPUS;
    strcpy(test3.destination, "LRLRL");
    makeAction(g, test3);
    assert(getCampuses(g, UNI_C) == 3);
    
    throwDice(g, 2);
    assert(getCampuses(g, UNI_A) == 3);
    assert(getCampuses(g, UNI_B) == 3);
    assert(getCampuses(g, UNI_C) == 3);
    
    disposeGame(g);
}
 
void test_getIPs (void){
    //Tayyyy
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    
    throwDice(g, 2);
    action test1;
    test1.actionCode = OBTAIN_IP_PATENT;
    makeAction(g,test1);
    
    assert(getIPs(g, UNI_A) == 1);
    
    throwDice(g, 2);
    action test2;
    test2.actionCode = OBTAIN_IP_PATENT;
    makeAction(g,test2);
    
    assert(getIPs(g, UNI_B) == 1);
    
    disposeGame(g);
}
 
void test_getPublications (void){
    //Jennivine
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    
    throwDice(g, 2);
    action test1;
    test1.actionCode = OBTAIN_PUBLICATION;
    makeAction(g,test1);
    
    assert(getPublications(g, UNI_A) == 1);
    
    throwDice(g, 2);
    action test2;
    test2.actionCode = OBTAIN_PUBLICATION;
    makeAction(g,test2);
    
    assert(getPublications(g, UNI_B) == 1);
    
    disposeGame(g);
}
 
void test_getStudents (void){
    //Lily
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    
    // test students are gained with dice role
    throwDice(g,11);
    assert(getStudents(g, UNI_A, STUDENT_MTV) == 2);
    
    throwDice(g,9);
    assert(getStudents(g, UNI_B, STUDENT_BQN) == 4);
    
    throwDice(g,8);
    assert(getStudents(g, UNI_C, STUDENT_MTV) == 2);
    assert(getStudents(g, UNI_C, STUDENT_MJ) == 2);
    
    throwDice(g, 5);
    assert(getStudents(g, UNI_B, STUDENT_BPS) == 4);
    
    throwDice(g, 6);
    assert(getStudents(g, UNI_C, STUDENT_MJ) == 2);
    
    // test students converted when 7 is rolled
    throwDice(g,7);
    assert(getStudents(g, UNI_A, STUDENT_THD) == 3);
    assert(getStudents(g, UNI_B, STUDENT_THD) == 2);
    assert(getStudents(g, UNI_C, STUDENT_THD) == 3);
    
    // test when students are retrained
    action test1;
    test1.actionCode = RETRAIN_STUDENTS;
    test1.disciplineFrom = STUDENT_THD;
    test1.disciplineTo = STUDENT_MMONEY;
    makeAction(g, test1);
    assert(getStudents(g, UNI_A, STUDENT_THD) == 0);
    assert(getStudents(g, UNI_A, STUDENT_MMONEY) == 1);
    
    disposeGame(g);
}
 
void test_getExchangeRate (void){
    //Jennivine
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8};
    Game g = newGame(disciplines, dice);
    
    //To start with, all exchange rates should be 3 for all players.
    int uni = UNI_A;
    while (uni <= UNI_C) {
        int from;
        throwDice(g, 8);
        from = STUDENT_BPS;
        while (from <= STUDENT_MMONEY) {
            int to = STUDENT_THD;
            while (to <= STUDENT_MMONEY) {
                assert(getExchangeRate(g, uni, from, to) == 3);
                to++;
            }
            from++;
        }
        uni++;
    }
    
    //Each player has to build campuses next to the retraining centers
    //to get the bonuses.
    throwDice(g, 8);
    
    // UNI_A building its first arc
    action makeARC = { OBTAIN_ARC, "R", 0 , 0 };
    makeAction(g, makeARC);
    // Second arc
    action makeSecondARC = { OBTAIN_ARC, "RR", 0 , 0 };
    makeAction(g, makeSecondARC);
    
    //Uni_A builds campus next to retraining centre
    action buildCampus = { BUILD_CAMPUS, "RR", 0, 0 };
    makeAction(g, buildCampus);
    
    //UNI_A can retrain 3 students from BPS into any other kind
    assert (getExchangeRate (g, UNI_A, STUDENT_BPS, STUDENT_THD) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_BPS, STUDENT_BQN) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_BPS, STUDENT_MJ) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_BPS, STUDENT_MTV) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_BPS, STUDENT_MMONEY) == 3);
  
    //UNI_A can retrain 2 students from B? into any other kind
    assert (getExchangeRate (g, UNI_A, STUDENT_BQN, STUDENT_THD) == 2);
    assert (getExchangeRate (g, UNI_A, STUDENT_BQN, STUDENT_BPS) == 2);
    assert (getExchangeRate (g, UNI_A, STUDENT_BQN, STUDENT_MJ) == 2);
    assert (getExchangeRate (g, UNI_A, STUDENT_BQN, STUDENT_MTV) == 2);
    assert (getExchangeRate (g, UNI_A, STUDENT_BQN, STUDENT_MMONEY) == 2);
    
    //UNI_A can retrain 3 students from MJ into any other kind
    assert (getExchangeRate (g, UNI_A, STUDENT_MJ, STUDENT_THD) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MJ, STUDENT_BPS) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MJ, STUDENT_BQN) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MJ, STUDENT_MTV) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MJ, STUDENT_MMONEY) == 3);
    
    //UNI_A can retrain 3 students from MTV into any other kind
    assert (getExchangeRate (g, UNI_A, STUDENT_MTV, STUDENT_THD) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MTV, STUDENT_BPS) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MTV, STUDENT_BQN) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MTV, STUDENT_MJ) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MTV, STUDENT_MMONEY) == 3);
    
    //UNI_A can retrain 3 students from MMONEY into any other kind
    assert (getExchangeRate (g, UNI_A, STUDENT_MMONEY, STUDENT_THD) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MMONEY, STUDENT_BPS) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MMONEY, STUDENT_BQN) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MMONEY, STUDENT_MJ) == 3);
    assert (getExchangeRate (g, UNI_A, STUDENT_MMONEY, STUDENT_MTV) == 3);
    
    //other UNIs should not be affected
    uni = UNI_B;
    while (uni <= UNI_C) {
        int from;
        throwDice(g, 8);
        from = STUDENT_BPS;
        while (from <= STUDENT_MMONEY) {
            int to = STUDENT_THD;
            while (to <= STUDENT_MMONEY) {
                assert(getExchangeRate(g, uni, from, to) == 3);
                to++;
            }
            from++;
        }
        uni++;
    }
 
    disposeGame(g);
}
