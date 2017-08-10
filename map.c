#include <stdint.h>

// general type for a map of void* to void*. Note here that the map
// doesn't store anything; that's handled separately.
typedef struct {
    size_t size;
    size_t width;
    void** seen;
    void* assoc;
} Map;

static unsigned checksum(void* data, int width)
{
    unsigned sum = 0;
    while(width--) sum += 1777 * ((char*)data)[width];
    return sum;
}

int map_contains(Map* m)
