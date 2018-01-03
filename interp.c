#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int16_t i16;
typedef double f64;

enum {
	SRATE = 48000,
	STEP = SRATE / 800,
	SAMP_LEN = 1024,
};

i16 wave[SAMP_LEN];
i16 get(size_t pos) {
	return wave[pos % SAMP_LEN];
}
i16 get_linear(f64 pos) {
	f64 t = fmod(pos, 1.0);
	f64 v1 = get(pos);
	f64 v2 = get(pos-1);
	f64 d1 = v1 - v2;
	return v2 + d1*t;
}

int main()
{
	for(int i=0; i<SAMP_LEN; ++i) {
		wave[i] = INT16_MAX * sin(i * 2.0 * acos(-1) / SAMP_LEN);
	}
	f64 pos = 0, next_samp = 0;
	for(;;) {
		i16 samp = get_linear(pos);
		putchar(samp & 15);
		putchar(samp >> 8);
		pos += (1.0/STEP);
	}
}
