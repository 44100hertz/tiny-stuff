#include <stdio.h>

int main() {
    for(int i=0; i<10; ++i) {
        const int b = i;
        printf("%d\n", b);
    }
}
