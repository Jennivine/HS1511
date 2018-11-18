#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	int side;
	int row, col;
    int i;
    
	printf("enter the side length for your diamond: ");
	scanf("%d",&side);
    
	int total = side * 2 - 1;
    
	row = 0;
    while (row < total) {
        col = 0;
		i = 0;
        while (col < total) {
            if ((col >= (side - 1) - row && col <= (side - 1) + row) &&
                (col >= row - (side - 1) && col <= 3 * (side - 1) - row)) {
                
                if (col <= (total-1)/2) {
                    printf("%c",'A' + i);
                    i++;
                } else {
                    printf("%c",'A' + i - 2);
                    i--;
                }
                
            } else {
                printf(" ");
            }
            col++;
        }
        
        printf("\n");
        row++;
    }
    
	return EXIT_SUCCESS;
}
