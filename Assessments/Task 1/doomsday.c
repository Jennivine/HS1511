/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  This program by Jennivine Chen
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

#define JANUARY_DOOMSDAY_LEAPYEAR 4
#define JANUARY_DOOMSDAY_NOT_A_LEAPYEAR 3
#define FEBRUARY_DOOMSDAY_LEAPYEAR 29
#define FEBRUARY_DOOMSDAY_NOT_A_LEAPYEAR 28
#define MARCH_DOOMSDAY 7
#define APRIL_DOOMSDAY 4
#define MAY_DOOMSDAY 9
#define JUNE_DOOMSDAY 6
#define JULY_DOOMSDAY 11
#define AUGUST_DOOMSDAY 8
#define SEPTEMBER_DOOMSDAY 5
#define OCTOBER_DOOMSDAY 10
#define NOVEMBER_DOOMSDAY 7
#define DECEMBER_DOOMSDAY 12

int dayOfWeek (int doomsday, int leapYear, int month, int day);

int main (int argc, char *argv[]) {
    assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);
    
    assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
    assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);
    
    assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);
    
    printf ("all tests passed - You are awesome!\n");
    return EXIT_SUCCESS;
}


// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
    int dayOfWeek;
    int monthDoomsday = 0;
    int dayMinus;
    int dayOfWeekMod;
    
    if (month == 1) {
        if (leapYear) {
            monthDoomsday = JANUARY_DOOMSDAY_LEAPYEAR;}
        else {
            monthDoomsday = JANUARY_DOOMSDAY_NOT_A_LEAPYEAR;}
    } else if (month == 2) {
        if (leapYear) {
            monthDoomsday = FEBRUARY_DOOMSDAY_LEAPYEAR;}
        else {
            monthDoomsday = FEBRUARY_DOOMSDAY_NOT_A_LEAPYEAR;}
    } else if (month == 3) {
        monthDoomsday = MARCH_DOOMSDAY;
    } else if (month == 4) {
        monthDoomsday = APRIL_DOOMSDAY;
    } else if (month == 5) {
        monthDoomsday = MAY_DOOMSDAY;
    } else if (month == 6) {
        monthDoomsday = JUNE_DOOMSDAY;
    } else if (month == 7) {
        monthDoomsday = JULY_DOOMSDAY;
    } else if (month == 8) {
        monthDoomsday = AUGUST_DOOMSDAY;
    } else if (month == 9) {
        monthDoomsday = SEPTEMBER_DOOMSDAY;
    } else if (month == 10) {
        monthDoomsday = OCTOBER_DOOMSDAY;
    } else if (month == 11) {
        monthDoomsday = NOVEMBER_DOOMSDAY;
    } else if (month == 12) {
        monthDoomsday = DECEMBER_DOOMSDAY;
    }
    
    dayMinus = day - monthDoomsday;
    dayOfWeekMod = dayMinus % 7;
    dayOfWeek = doomsday + dayOfWeekMod;
    
    if (dayOfWeek < 0){
        dayOfWeek += 7;
    } else if (dayOfWeek > 6){
        dayOfWeek -= 7;
    }
    
    return (dayOfWeek);
}
