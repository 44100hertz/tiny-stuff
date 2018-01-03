#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASS_LEN 16

int main() {
    srand(clock());
    char ascii_min = ' ', ascii_max = '~';
    char ascii_range = ascii_max - ascii_min;

    char pass[PASS_LEN+1];
    for(int i=0; i<PASS_LEN; ++i) {
        pass[i] = rand() % ascii_range + ascii_min;
    }
    pass[PASS_LEN] = '\0';
    puts(pass);

    return 0;
}
