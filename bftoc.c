#include <stdio.h>
#include <string.h>

int handle()
{
    int accum = 1;
    char c;
    switch(c=getchar()) {
    case '<':
        while((c=getchar())=='<') ++accum;
        printf("h+=%d;\n", accum);
        break;
    case '>':
        while((c=getchar())=='>') ++accum;
        printf("h-=%d;\n", accum);
        break;
    case '+':
        while((c=getchar())=='+') ++accum;
        printf("t[h]+=%d;\n", accum);
        break;
    case '-':
        while((c=getchar())=='-') ++accum;
        printf("t[h]-=%d;\n", accum);
        break;
    case '.': puts("putchar(t[h]);"); break;
    case ',': puts("t[h] = getchar();"); break;
    case '[': puts("while(t[h]) {"); break;
    case ']': puts("}"); break;
    }
    return 0;

}
int main()
{
    puts(
        "#include <stdio.h>\n"
        "#include <stdint.h>\n"
        "int main() {\n"
        "    uint8_t t[256] = {0};\n"
        "    uint8_t h=0;");
    char c;
    int tab = 1;
    while((c=getchar())!=EOF) {
        if(!strchr("<>+-[]", c)) break;
        do {
            if(c==']') tab--;
            for(int i=tab; i--;) printf("    ");
            if(c=='[') tab++;
        } while(handle(c));
    }
    puts(
        "    return 0;\n"
        "}");
    return 0;
}
