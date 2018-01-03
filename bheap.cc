#include <stdlib.h>

struct bheap {};

int hash(void *item)
{
        return ((long)item)>>3;
}

void insert(struct bheap *heap, void *item)
{
}

void *get(struct bheap *heap)
{
}

int main()
{
        int x = 100;
        printf("%d\n", hash(&x));
}
