#include <stdio.h>

#include "charset.hh"

char good_char(char c) {
    const charset::Charset* where[] = { &charset::base32,
                                        &charset::hex,
                                        &charset::hex };
    static int pos = 0;
    if(where[pos][0][c]) {
        char out = where[pos][0][c];
        pos = (pos+1) % 3;
        return out;
    }
    return 0;
}

int main() {
    for(;;) {
        char c = getchar();
        if(c == '\n' || (c=good_char(c))) {
            printf("%c", c);
        } else {
            putchar('%');
        };
//        fflush(stdout);
    }
    return 0;
}
