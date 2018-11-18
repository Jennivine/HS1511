//
//  dragon.c
//  
//
//  Created by Jennivine on 4/3/18.
//

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[]) {
    int first, second, third;
    scanf ("%d %d %d", &first, &second, &third);
    
    if ((first < second) && (first < third)){
        printf("%d\n",first);
        if (second < third){
            printf("%d\n",second);
            printf("%d\n",third);
        } else {
            printf("%d\n",third);
            printf("%d\n",second);
        }
    } else if ((second < first) && (second < third)){
        printf("%d\n",second);
        if (first < third){
            printf("%d\n",first);
            printf("%d\n",third);
        } else {
            printf("%d\n",third);
            printf("%d\n",first);
        }
    } else if ((third < first) && (third < second)) {
        printf("%d\n",third);
        if (first < second){
            printf("%d\n",first);
            printf("%d\n",second);
        } else {
            printf("%d\n",second);
            printf("%d\n",first);
        }
    }
    
}
