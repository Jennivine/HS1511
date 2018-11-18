/*
 
 TayLyVine
 
 March 28, 2018
 
 Frequency analysis code
 
 */



/*
 
 repeatedly reads in a character, or a collection of characters from standard input using the getchar() function from stdio.h,
 
 works out the frequency of each letter of the alphabet in the input.
 
 Stop reading when you reach the end of input/end-of-file (getchar returns -1 after that happens).
 
 
 
 Your program should in a useful format print out the number of characters it read, the number of letters it read, and then for
 
 each letter print out the proportion of the total number of letters which
 
 were that particular letter (merge upper and lower case versions of letters in this statistic).
 
 You can compute and print out other statistics too if you you think they will be useful to help you crack encoded messages.
 
 
 
 Your program needs to work with large input text files (many megabytes) so make sure your program isn't too slow.
 
 (Input the contents of the files into your program using the file redirection techniques you talk about in your tutorial this week)
 
 */



#include <stdio.h>

#include <stdlib.h>

#define STOP -1

#define NUM_ASCII 128



int main (int argc, char* argv[]) {
    int frequency[NUM_ASCII] = {0}; // array of length of ASCII, each element as 0
    
    // get character to from user
    
    // getchar() reads and returns one character from the keyboard
    // returns -1 when the input is finished / end-of-file is reached
    int character = getchar();
    
    int total = 0;
    
    //takes in input and count the frequency of each letter
    while (character != STOP) {
        frequency[character]++;
        //count the number of letters in file
        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')){
            total ++;
        }
        character = getchar();
    }
    
    int letter = 0;
    
    while (letter < NUM_ASCII){
        if (letter >= 'A' && letter <= 'Z'){
            // letter+20 is the lower case version of each upper case letter
            int letterFrequency = frequency[letter] + frequency[letter+32];
            printf("%c: %d\n", letter, letterFrequency);
        }
        letter ++;
    }
    return EXIT_SUCCESS;
}
