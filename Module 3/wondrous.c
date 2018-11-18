//
//  wondrous.c
//  
//
//  Created by Jennivine on 16/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int printWondrous (int start);
void testWondrous(void);

int main (int argc, char *argv[]) {
    int x;
    scanf("%d", &x);
    
    printWondrous(x);
    return EXIT_SUCCESS;
}


int printWondrous (int start) {
    int ans = 1;
    printf("%d ",start);
    while (start != 1) {
        if (start % 2 == 0){
            start = start / 2;
        } else {
            start = 3*start + 1;
        }
        printf("%d ",start);
        ans += 1;
    }
    printf("\n");
    return ans;
}

void testWondrous(void){
    //random testing
    assert (printWondrous(2) == 1);
    assert (printWondrous(3) == 8);
    assert (printWondrous(7) == 17);
    assert (printWondrous(8) == 4);
    assert (printWondrous(17) == 13);
    assert (printWondrous(21) == 8);
    assert (printWondrous(23) == 16);
    
    //extreme case
    assert (printWondrous(109) == 114);
}
