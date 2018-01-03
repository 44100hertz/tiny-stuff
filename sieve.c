#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
typedef unsigned long usize;
struct primes {
    int size;
    int *primes;
} find_primes(int num) {
    int *primes = calloc(sqrt(num)+1, sizeof(int));
    bool *sieve = calloc(num, sizeof(bool));
    int count = 0;
    for(int i=2; i<num; ++i) {
        if(!sieve[i]) {
            primes[count++] = i;
            for(int j=0; (j+=i)<num;) sieve[j] = true;
        }
    }
    return (struct primes){count, primes};
}
int main() {
    struct primes p = find_primes(100);
    for(int i=0; i<p.size; ++i) {
        printf("%d\n", p.primes[i]);
    }
    return 0;
}
