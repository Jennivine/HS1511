//
//  reverse.c
//  
//
//  Created by Jennivine on 7/4/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

char *reverse(char *message);

char *reverse(char *message) {
    int n = strlen(message);
    char *reversed = malloc(sizeof(char) * n + 1);
    
    int i = 0;
    while (i < n) {
        reversed[i] = message[n - i -1];
        i += 1;
    }
    reversed[i] = 0;
    
    return reversed;
}
