#include <stdio.h>
struct coin {
	char* name;
	int value;
} const coin[] = {
	{"Quarter", 25},
	{"Dime",    10},
	{"Nickel",   5},
	{"Penny",    1},
};
const int num_coins = 4;
struct count {
	int v[4];
};
struct count count_add(struct count with) {
	struct count count;
	for(int i=0; i<num_coins; ++i) count.v[i] += with.v[i];
	return count;
}
int try_change(int *change) {
	for(int i=0; i<num_coins; ++i) {
		if(*change - coin[i].value >= 0) {
			*change -= coin[i].value;
			return i;
		}
	}
}
struct count count_change(int change) {
	struct count count;
	while(change > 0) {
		count.v[try_change(&change)]++;
	}
	return count;
}
void count_print(struct count count) {
	for(int i=0; i<num_coins; ++i) {
		printf("%s: %d", coin[i].name, count[i].v);
	}
}
int main() {
	struct count total;
	for(int i=0; i<100; ++i) {
		total = count_add(total, count_change(i));
	}
	count_print(total);
	return 0;
}
