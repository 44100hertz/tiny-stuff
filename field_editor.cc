#include <stdio.h>

#include "base32.hh"

int main() {
    for(;;) {
        char c = getchar();
        if(c == '\n' || base32.valid(c)) {
            printf("%c", base32[c]);
        } else {
            putchar('%');
        };
//        fflush(stdout);
    }
    return 0;
}
