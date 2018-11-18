// sample unit tests for the escapeSteps function

// to run these tests:
//   1. rename or comment out the main function in mandelbrot.c
//   2. compile the tests using
//     gcc -Wall -Werror -O -std=c99 -o mandelbrotTest mandelbrotEscape.c mandelbrotTest.c
//   3. run mandelbrotTest

// richard buckland
// 29 april 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "mandelbrot.h"

int escapeSteps(double x, double y) {
   double r = 0;
   double i = 0;
   double nextR;
   double nextI;
   double iterations = 0;
    
   while ((r*r + i*i <= 4) && (iterations < 256)) {
        nextR = r*r - i*i + x;
        nextI = 2*r*i + y;
        
        r = nextR;
        i = nextI;
        
        iterations++; //counts how many iterations it takes
    }
    
    return iterations;
}
