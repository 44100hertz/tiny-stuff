#include <stdio.h>

int main()
{
    void nested(int arg) {
        printf("%d", arg);
    }

    nested(3);
    nested(5);
}
