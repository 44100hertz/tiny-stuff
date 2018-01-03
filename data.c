#include <stdio.h>

struct data {
    int x, y;
};

constexpr struct data Data(int x, int y) {
    puts("wow");
    return (struct data){x, y};
}

const struct data data[] = {
    Data(0, 1)
};

int main() {
    printf("%d\n", data[0].x);
    return 0;
}
