//
//  warmupPracExam.c
//  
//
//  Created by Jennivine on 23/3/18.
//

#include <stdio.h>
#include <stdlib.h>

void makeCrossFlag(int n);

int main (int argc, char *argv[]){
    int n;
    scanf("%d",&n);
    
    makeCrossFlag(n);
    
    return EXIT_SUCCESS;
}

void makeCrossFlag(int n){
    int row = 0;
    while (row < n) {
        int col = 0;
        while (col < n){
            if (row == col || col == (n-row-1)){
                printf("#");
            } else {
                printf("-");
            }
            col ++;
        }
        printf("\n");
        row ++;
    }
}
