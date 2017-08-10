#include <stdio.h>

void inc(int* i) {
    *i += 1;
    printf("%d\n", *i);
}

int main()
{
    {
        int x = 12;
        inc(&x);
    }
    inc(&(int){4});
}
