#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// general type for a set of void* to void*. Note here that the set
// doesn't store anything; that's handled separately.
typedef struct {
    size_t size;
    size_t width;
    void** set;
} Set;

static size_t checksum(void* data, int width)
{
    size_t sum = 0;
    while(width--) sum += 1777 * ((char*)data)[width];
    return sum;
}

int set_contains(Set* m, void* value)
{
    size_t place = checksum(value, m->width);
    while(1) {
        if(m->set[place]) {
            int diff = memcmp(m->set[place], value, m->width);
            if(diff) {
                place = (place+1) % set_size; // linear probing
            } else {
                return 1;
            }
        } else {
            m->set[place] = value;
            return 0;
        }
    }
}

