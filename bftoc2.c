#include <stdio.h>

int main()
{
    FILE* f = fopen("out.c", "w");
    fprintf(f, "char t[256];");
    fprintf(f, "int h=0;");
    while(c=getchar()!=EOF) {
        switch(c) {
        case '<': fprintf(f, "h=(h+1)%256;"); break;
        case '>': fprintf(f, "h=(h-1)%256;"); break;
        case '+': fprintf(f, "++t[h];"); break;
        case '-': fprintf(f, "--t[h];"); break;
        case '.': fprintf(f, "putchar(t[h]);"); break;
        case ',': fprintf(f, "t[h]=getchar();"); break;
        case '[': fprintf(f, "while(t[h]){;"); break;
        case ']': fprintf(f, "while(t[h]){;"); break;
        }
    }
    fclose(f);
    return 0;
}
