#include <stdio.h>

void nested(int arg);
void retarded(int arg);

int main()
{
    void nested(int arg) {
        printf("%d\n", arg);
    }

    retarded(3);
    retarded(5);
}

void retarded(int arg)
{
    printf("retarded");
    nested(arg);
}
