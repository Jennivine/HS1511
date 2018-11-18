//
//  leapYearFunction.c
//  
//
//  Created by Jennivine on 4/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_OF_GREG_CALENDAR 1582

int isLeapYear (int year);

int main (int argc, const char * argv[]) {
    int year;
    
    printf("please enter the year you are interested in\n");
    scanf("%d", &year);
    
    assert (year >= START_OF_GREG_CALENDAR);
    
    int leapYear = isLeapYear(year);
    
    
    return leapYear;
}

int isLeapYear (int year) {
    if ((year % 400) == 0){
        printf("%d is a leap year!\n", year);
        return 1;
    } else if ((year % 100) == 0){
        printf("%d is not a leap year!\n", year);
        return 0;
    } else if ((year % 4) == 0){
        printf("%d is a leap year!\n", year);
        return 1;
    } else {
        printf("%d is not a leap year!\n", year);
        return 0;
    }
    
}
