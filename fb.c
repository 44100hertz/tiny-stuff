#include <stdio.h>
int main() {
    for(int i=0; i<100; ++i) {
        f = i%3;
        b = i%5;
        if(!f) printf("fizz");
        if(!b) printf("buzz");
        if(f&&b) printf("%d\n", i);
        puts("");
    }
}
