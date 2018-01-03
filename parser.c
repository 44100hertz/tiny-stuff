#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expr {
	char *token;
	struct expr *next;
};

struct expr *parse(char **pos) {
	struct expr *expr = calloc(sizeof(struct expr), 1);
	struct expr *head = expr;
	char *token = *pos;
	int tok_len = 0;
	while(1) {
		switch(**pos) {
		case '(':
			head = head->next = parse(pos);
			break;
		case ')':
					
		}
		(*pos)++;
	}
}

int main() {

}
