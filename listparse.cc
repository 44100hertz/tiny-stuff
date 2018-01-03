#include <stdio.h>
#include <vector>

struct Expr {
    const char* start;
    const char* end;
    std::vector<Expr> sub;
    void parse(const char *&pos) {
	if (*pos == '(') {
	    Expr next = {pos, pos};
	    while(*pos != ')') {
		next.parse(pos);
	    }
	} else {
	    Expr next {pos, pos};
	    while(*pos != ' ') pos++;
	    next.end = pos;
	    while(*pos == ' ') pos++;
	    this->sub.push_back(next);
	}
    }
    void print() {
	for(auto& expr : this->sub) {
	    putchar('(');
	    for(const char* pos = this->start; pos != this->end; ++pos)
		putchar(*pos);
	    putchar(')');
	}
    }
};

int main() {
    Expr e;
    const char* str = "(a (b c d))";
    const char* cc = str;
    e.parse(cc);
    e.print();
    return 0;
}
