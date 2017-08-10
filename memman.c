#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint16_t ptr;
typedef uint8_t byte;
const ptr mem_size = UINT16_MAX;

byte* mem;
byte* head;

typedef struct {
    ptr size;
    byte alive;
} Header;

// move the allocation pointer forward, returning where it was
byte* reserve(ptr size)
{
    byte* from = head;
    head += size;
    assert(head-mem <= mem_size);
    return from;
}

// write a header and reserve the memory
ptr alloc(ptr size)
{
    *(Header*)reserve(sizeof(Header)) = (Header){
        .size = size,
        .alive = 1,
    };
    return reserve(size) - mem;
}

void unalloc(ptr off)
{
    Header* b = &((Header*)mem)[off-1];
    b->alive = 0;
}

int main()
{
    mem = malloc(mem_size);
    head = mem;

    ptr a = alloc(99);
    ptr b = alloc(999);
    printf("%d %d\n", a, b);
    unalloc(a);

    free(mem);
}
