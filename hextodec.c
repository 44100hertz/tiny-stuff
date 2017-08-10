#include <stdio.h>

int hex2dec(char* buf, int len) {
    int sum = 0, i, idx;
    for(i=0,idx=len; idx--; ++i)
        sum += buf[i]%10 << (idx*8) + buf[i]/10 << (idx*8+4);
    return sum;
}

int main()
{
    char array[] = {0, 0, 01, 90};
    int sum = hex2dec(array, 4);
    printf("%d\n", sum);
    return 0;
}
