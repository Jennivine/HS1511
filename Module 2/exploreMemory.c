//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//

#include <stdio.h>
#include <stdlib.h>

long add (int x, int y);

int main(int argc, const char * argv[]) {
    
    char c ='a';
    
    unsigned long ul       = 0;
    unsigned int ui        = 1;
    unsigned long long ull = 2;
    unsigned short us      = 3;
    
    signed long sl       = 4;
    signed int si        = 5;
    signed long long sll = 6;
    signed short ss      = 7;
    
    long l       = 8;
    int i        = 9;
    long long ll = 10;
    short s      = 11;
    
    float f = 3.1;
    double d = 3.14;
    
 
    printf("char has a size of %lu\n",sizeof(c));
    
    printf("unsigned long has a size of %lu\n", sizeof(ul));
    printf("unsigned int has a size of %lu\n", sizeof(ui));
    printf("unsigned long long has a size of %lu\n", sizeof(ull));
    printf("unsigned short has a size of %lu\n", sizeof(us));
    
    printf("signed long has a size of %lu\n", sizeof(sl));
    printf("signed int has a size of %lu\n", sizeof(si));
    printf("signed long long has a size of %lu\n", sizeof(sll));
    printf("signed short has a size of %lu\n", sizeof(ss));
    
    printf("long has a size of %lu\n", sizeof(l));
    printf("int has a size of %lu\n", sizeof(i));
    printf("long long has a size of %lu\n", sizeof(ll));
    printf("short has a size of %lu\n", sizeof(s));
    
    printf("float has a size of %lu\n", sizeof(f));
    printf("double has a size of %lu\n", sizeof(d));
    
    
    printf("%p\n",&c);
    
    printf("%p\n",&ul);
    printf("%p\n",&ui);
    printf("%p\n",&ull);
    printf("%p\n",&us);
    
    printf("%p\n",&sl);
    printf("%p\n",&si);
    printf("%p\n",&sll);
    printf("%p\n",&ss);
    
    printf("%p\n",&l);
    printf("%p\n",&i);
    printf("%p\n",&ll);
    printf("%p\n",&s);
    
    printf("%p\n",&f);
    printf("%p\n",&d);
    
    return EXIT_SUCCESS;
}
