#include <stdio.h>

enum {
    A1,
    A2,
    NUM_A,
};

enum {
    B1,
    B2,
    B3,
    NUM_B,
};

const char* strings[NUM_A][NUM_B] = {
    [A1] = {
        [B1] = "hello,",
        [B2] = "world.\n",
        [B3] = "",
    },
    [A2] = {
        [B1] = "",
        [B2] = "",
        [B3] = "",
    },
};

const char* strings =
    "hello,  ",
    "world.\n ",
    "        ",
    "        ",
    "        ",
    "        ";

char* getstring(int a, int b) {
    switch(a) {
    case A1: switch(b) {
        case B1: return "hello,";
        case B2: return "world.\n";
        case B3: return "";
        }
        break;
    case A2: switch(b) {
        case B1: return "";
        case B2: return "";
        case B3: return "";
        }
        break;
    }
}

int main() {
    for(int a=0; a<NUM_A; ++a) {
        for(int b=0; b<NUM_B; ++b) {
            puts(strings[a][b]);
            puts(getstring(a, b));
        }
    }
}
