#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int SIZE = 1024;
const int THREADS = 4;
const int CHUNK_SIZE = 64;

pthread_mutex_t count_lock;
int count;
int* all_nums;

void *dothing(void* data) {
    while (1) {
        pthread_mutex_lock(&count_lock);
        int off = count * CHUNK_SIZE;
        printf("%d\n", count);
        count++;
        pthread_mutex_unlock(&count_lock);
        if(off < SIZE) {
            int upper = off+CHUNK_SIZE;
            if(upper > SIZE) {
                upper = SIZE;
            }
            for(int i=off; i<upper; ++i) {
                all_nums[i] = i;
            }
        } else {
            puts("done");
            return NULL;
        }
    }
}

int main() {
    pthread_t threads[THREADS];
    all_nums = malloc(SIZE);
    count = 0;
    pthread_mutex_init(&count_lock, NULL);
    for(int i=0; i<THREADS; ++i) {
        pthread_create(&threads[i], NULL, dothing, NULL);
    }
    for(int i=0; i<THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    /* for(int i=0; i<SIZE; ++i) { */
    /*     printf("%03d ", all_nums[i]); */
    /*     puts(""); */
    /* } */
    return 0;
}
