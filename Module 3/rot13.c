/*
Jennivine the bean, Tay the bae and Lily the chilli
21 March 2018
We cry over the alphabet 13 places forward
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define ROT_13 13

char encode (char letter);
void testEncode (void);

int main(int argc, char* argv[]){
    testEncode ();
    printf ("yes gurlllllllllllllllll\n");
    return EXIT_SUCCESS;
}

char encode (char letter){
    if (letter >= 'A' && letter <= 'Z'){
        if (letter > 'M'){
            letter -= ROT_13;
        } else {
            letter += ROT_13;
        }
    } else if (letter >= 'a' && letter <= 'z'){
        if (letter > 'm'){
            letter -= ROT_13;
        } else {
            letter += ROT_13;
        }
    }
    return letter;
}

void testEncode (void){
    assert(encode ('m') == 'z');
    assert(encode ('M') == 'Z');
    assert(encode ('A') == 'N');
    assert(encode ('p') == 'c');
    assert(encode ('d') == 'q');
    assert(encode ('a') == 'n');
    assert(encode ('b') == 'o');
    assert(encode ('z') == 'm');
    assert(encode ('8') == '8');
    assert(encode ('.') == '.');
}
