#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int char_uniq(const char* in) {
    char seen[256] = {0};
    int count=0;
    for(; *in; ++in)
        if(!seen[*in]) {
            seen[*in] = 1;
            ++count;
        }
    return count;
}

unsigned checksum(const void* data, int width) {
    unsigned sum = 0;
    while(width--) sum += 1777 * ((char*)data)[width];
    return sum;
}

int set_contains(const void** set, int set_size,
                 const void* value, int width) {
    unsigned place = checksum(value, width) % set_size;
    while(1) {
        if(set[place]) {
            int diff = memcmp(set[place], value, width);
            if(diff) {
                place = (place+1) % set_size;
            } else {
                return 1;
            }
        } else {
            set[place] = value;
            return 0;
        }
    }
}

int fat_uniq(const void* in, int width, int num) {
    int count = 0;
    int seen_size = num*2;
    const void** seen_set = calloc(sizeof(void*), seen_size);
    for(int i=0; i<num; ++i) {
        const void* inval = in + i*width;
        if(!set_contains(seen_set, seen_size, inval, width)) ++count;
    }
    free(seen_set);
    return count;
}

int main() {
    const int thems[] = {1, 2, 3, 3, 4, 5, 5, 1, 2, 4, 5};
    printf("%d\n", fat_uniq(thems, sizeof(int), sizeof(thems)/sizeof(int)));
    return 0;
}
