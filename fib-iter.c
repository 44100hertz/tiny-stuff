#include <stdio.h>

struct fib {
    int on, last;
};

const struct fib fib_init = {
    .on = 1,
    .last = 0,
};

struct fib fib_iter(struct fib last) {
    struct fib next;
    next.last = last.on;
    next.on = last.on + last.last;
    return next;
}

int main()
{
    struct fib f = fib_init;
    while((f = fib_iter(f)).on < 100) {
        printf("%d\n", f.on);
    }
    return 0;
}
