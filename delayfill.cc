#include <stdio.h>
#include <stdlib.h>

const int BUFSIZE = 1024, TICKSIZE = 4000;

template <typename T>
T min(T a, T b) {
	return a > b ? b : a;
}

void fill(int* buf, int from, int len) {
	printf("Filling: %d to %d\n", from, from+len);
	for(int i=0; i<len; ++i) {
		buf[i] = from+i;
	}
}

void fill_range(int* buf) {
	static int at = 0;
	int wanted = at + BUFSIZE - 1;
	while (at < wanted) {
		int next_tick = (at / TICKSIZE + 1) * TICKSIZE;
		int next_at = min(next_tick, wanted);
		fill(buf, at, next_at-at);
		at = next_at;
	}
	puts("-- next --");
}

int main() {
	int* buf = malloc(sizeof(int) * BUFSIZE);
	for(int i=0; i<100; ++i) {
		fill_range(buf);
	}
	return 0;
}
