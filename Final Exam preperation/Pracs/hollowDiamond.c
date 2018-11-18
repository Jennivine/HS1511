

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	int side;
	int row, col;
	
	printf("enter the side length for your diamond: ");
	scanf("%d",&side);
	
	row = 0;
    while (row < side * 2 - 1) {
        col = 0;
        while (col < side * 2 - 1) {
            if (row <= (side - 1)) {
				//top half of the diamond
                if (col == (side - 1) - row || col == (side - 1) + row) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else {
				//bottom half of the diamond
                if (col == row - (side - 1) || col == 3 * (side - 1) - row) {
                    printf("*");
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