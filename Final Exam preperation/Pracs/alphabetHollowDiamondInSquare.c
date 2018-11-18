//
//  j.c
//  
//
//  Created by Jennivine on 12/6/18.
//

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    int side;
    int row, col;
    
    printf("enter the side length for your diamond: ");
    scanf("%d",&side);
    
    row = 0;
    int i = 0;
    while (row < side * 2) {
        col = 0;
        i  = 0;
        while (col < side * 2 ) {
            if (col < side){
                if ((row + col < side) || (row - col >= side)){
                    printf("%c",'A' + i);
                    i++;
                } else {
                    printf(" ");
                }
            } else {
                if ((row + col >= side*3-1) || (col - row >= side)){
                    printf("%c",'A' + i - 1);
                    i--;
                } else {
                    printf(" ");
                }
            }
            col++;
        }
        printf("\n");
        row++;
    }
    
    return EXIT_SUCCESS;
}
