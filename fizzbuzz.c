#include <stdio.h>

int main() {
	for(int i=1; i<=100; ++i) {
		if(i%3) {
			if(i%5) goto num;
			goto buzz;
		}
		printf("fizz");
		if(i%5) goto end;
buzz:
		printf("buzz");
		goto end;
num:
		printf("%d", i);
end:
		puts("");
	}
	return 0;
}
