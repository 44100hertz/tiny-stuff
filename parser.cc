#include <stdio.h>
#include <string.h>

struct parsable {
    int num_field;
    struct field field[num_field];
    void *data;
};
struct field {
    const char *id;
    int off;
};
struct data {
    int val1;
    int val2;
};
#define FIELD(o, x) {#x, o.##x}
struct field data_field[] = {
    FIELD(val1),
    FIELD(val2),
}
int main() {

}
