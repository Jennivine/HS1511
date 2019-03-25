/*
 * This program find the smallest starting value of a
 * Wondrous Sequence which has length over 1234
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LENGTH 1234
#define PRINT_LENGTH 1000
#define NUMBER_PER_LINE 5

int lengthWondrous (unsigned long long start);
void testlengthWondrous (void);

int main (int argc, char *argv[]) {
    testlengthWondrous ();
    
    unsigned long long start;
    int len = 0;
    int maxlen;
    int count = 0;
    
    printf("Start from number: ");
    scanf("%llu", &start);
    if ( start % 2 == 0 ) {
        start++;
    }
    
    printf("Current max length: ");
    scanf("%d", &maxlen);
    
    while (len <= MAX_LENGTH) {
        len = lengthWondrous (start);
        if (len > maxlen) {
            printf ("\nAWESOME! %llu has length %d\n",
                    start, len);
            maxlen = len;
            count = 0;
        } else if (len > PRINT_LENGTH) {
            printf ("%llu ", start);
            count++;
            if (count == NUMBER_PER_LINE) {
                printf ("\n");
                count = 0;
            }
        }
        start++;
        start++;
    }
    
    return EXIT_SUCCESS;
}

/* ------------------------
 * Function: lengthWondrous
 * ------------------------
 * Simulates a Wondrous Sequence and return its length
 *
 */

int lengthWondrous (unsigned long long start) {
    int length = 1;
    while (start > 1) {
        if (start % 2 == 0) {
            start /= 2;
        } else {
            start *= 3;
            start++;
        }
        length++;
    }
    return length;
}

/* ----------
 * Unit Tests
 * ----------
 */

void testlengthWondrous (void) {
    assert (lengthWondrous (1) == 1);
    assert (lengthWondrous (2) == 2);
    assert (lengthWondrous (3) == 8);
    assert (lengthWondrous (97) == 119);
    assert (lengthWondrous (1341234558) == 988);
    assert (lengthWondrous (17828259369) == 1214);
    assert (lengthWondrous (63389366647) == 1221);
    assert (lengthWondrous (75128138247) == 1229);
    assert (lengthWondrous (133561134663) == 1235);
    
    printf ("All tests passed. You're Awesome!\n");
    return;
}
