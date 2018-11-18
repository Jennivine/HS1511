//
//  danish.c
//  
//
//  Created by Jennivine on 16/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#define COL 12
#define ROW 5

void showDanish (void);

int main (int argc, char *argv[]){
    showDanish();
    return EXIT_SUCCESS;
}

void showDanish (void){
    int row = 0;
    while (row < ROW){
        int col = 0;
        
        if (row == 2){
            printf("\n");
            row ++;
        }
        
        while (col < COL){
            if (col == 2){
                printf(" ");
            } else {
                printf("*");
            }
            col++;
        }
        
        row++;
        printf("\n");
    }
}
