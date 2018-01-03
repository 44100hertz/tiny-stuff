#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
        BOARDW = 10,
        BOARDH = 10,
        BOARDSIZE = BOARDW*BOARDH,
};

struct dict {
        char **words;
        int len;
} dict_new(char *path);

void put_word(char *board, struct dict dict);

int main()
{
        struct dict dict = dict_new("/usr/share/dict/words");
        char board[BOARDSIZE] = {0};
        for(int i=0; i<10; ++i) {
                put_word(board, dict);
        }
        for(int i=0; i<BOARDSIZE; ++i) {
                if(i%BOARDW == 0) puts("");
                printf("%c ", board[i]);
        }
        return 0;
}

void put_word(char *board, struct dict dict)
{
        int pos = rand()>>8 % BOARDSIZE;
        int len = 0;
        for(int i=0; i<8; ++i) if (rand()>>16&1) ++len;
        int shifts[] = {1, BOARDW, -1, -BOARDW};
        int shift = shifts[rand()>>8&3];

        int iw = rand()>>8 % dict.len;
        char *word = dict.words[iw];
        while(*word && pos < BOARDSIZE && pos > 0) {
                printf("%d\n", pos);
                board[pos] = *word;
                pos += shift;
                word++;
        }
}

struct dict dict_new(char *path)
{
        struct dict dict = {NULL, 1};
        dict.words[0] = &strdup("pizza");
        return dict;
}

