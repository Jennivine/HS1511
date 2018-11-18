// extract.c
// funtions and types used to extract x,y,z values from a
// string containing a url of the form
// "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp"
// initially by richard buckland
// 13 April 2014
// your name here:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "extract.h"


int main (int argc, char *argv[]) {
    
    char * message = "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp";
    
    triordinate dat = extract (message);
    
    printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);
    
    assert (dat.x == 3.14);
    assert (dat.y == -0.141);
    assert (dat.z == 5);
    
    printf ("All tests passed. You are awesome!\n");
    
    return EXIT_SUCCESS;
}

triordinate extract(char *string) {
    triordinate t;
    sscanf(string, "http://almondbread.cse.unsw.edu.au:7191/tile_x%lf_y%lf_z%d.bmp", &t.x, &t.y, &t.z);
    return t;
}

long myAtoL(char *message) {
    long num = 0;
    int place = 1;
    int mod = 1;
    int n = strlen(message) - 1;
    
    int i = 0;
    while (i < (n + 1)) {
        char c = message[n - i];
        if (c == '-') {
            mod = -1;
        }else {
            long n = c - '0';
            
            num += n * place;
            place *= 10;
        }
        
        i += 1;
    }
    
    return num * mod;
}

double myAtoD(char *message) {
    double num = 0;
    int place = 1;
    int decimalAt = 1;
    int n = strlen(message) - 1;
    int mod = 1;
    
    int i = 0;
    while (i < (n + 1)) {
        char c = message[n - i];
        if (c == '.') {
            decimalAt = place;
        } else if (c == '-') {
            mod = -1;
        }else {
            double n = c - '0';
            num += n * place;
            place *= 10;
        }
        
        i += 1;
    }
    
    num /= decimalAt;
    return num * mod;
}
