#include <stdio.h>
int main() {
    int i=0;
loop:
    printf("%d\n", i);
    if(i++ < 100) goto loop;
    return 0;
}
