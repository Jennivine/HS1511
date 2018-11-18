#include <stdio.h>
#include <limits.h>

typedef unsigned long long ull;

ull next_collatz(ull n);
int collatz_chain_length(unsigned long n);

void find_long_one(long num_to_search) {
    unsigned long n = 752128138247;
    int max = 0;
    for (int i = 0; i < num_to_search; i++) {
        if (n % 1000000 == 0)
            printf(".\n");
        ull result = collatz_chain_length(n);
        //printf("n: %10llu      length: %d\n", n, result);
        if (result >= 1234) {
            printf("Found %lu\n", n);
            return;
        }
        if (result > max) {
            printf("New max: n = %10lu    length = %llu\n", n, result);
            max = result;
        }
        n++;
    }
}

void test() {
    printf("%lu\n", ULONG_MAX);
    ull n = 75128138247;
    printf("%llu\n", n);
    printf("%d\n", collatz_chain_length(n));
}

int main(void) {
    test();
//    find_long_one(1000000000);
    return 0;
}

ull next_collatz(ull n) {
    if (n % 2 == 0){
        return n/2;
    } else {
        return n*3 + 1;
    }
}

int collatz_chain_length(unsigned long n_) {
    ull n = (ull)n_;
    int count = 1;
    while (n > 1) {
        count++;
        n = next_collatz(n);
    }
    return count;
}

