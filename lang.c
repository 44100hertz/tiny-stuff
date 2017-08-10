#include <stdio.h>
#define TAPE_SIZE 256

int main(int argc, char** argv)
{
    FILE* f = argc>1 ? fopen(argv[1], "r") : stdin;
    int tape[TAPE_SIZE];
    int head = 0;
    fpos_t jumps[64];
    int at_jump = -1;
    int c;
    while((c=fgetc(f))!=EOF) {
        printf("%c\n", c);
        switch (c) {
        case '>': head = (head+1) % TAPE_SIZE; break;
        case '<': head = (head-1) % TAPE_SIZE; break;
        case '+': ++tape[head]; break;
        case '-': --tape[head]; break;
        case '.': putchar(tape[head]); break;
        case ',': tape[head] = getchar(); break;
        case '[':
            if(!tape[head]) {
                while(fgetc(f)!=']');
            } else {
                fgetpos(f, &jumps[++at_jump]);
            }
            break;
        case ']':
            if(tape[head]) {
                fsetpos(f, &jumps[at_jump--]);
            }
            break;
        }
    }
}
