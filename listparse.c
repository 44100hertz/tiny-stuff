#include <cstdio>
#include <vector>

struct Expr {
    char* start;
    char* end;
    std::vector<Expr> sub;
    void parse(char &*pos) {
	if (*pos == '(') {
	    Expr next { pos, pos };
	    while(*pos != ')') {
		pos++;
		next.parse(pos);
	    }
	} else {
	    Expr next { pos, pos };
	    while(*pos != ' ') next.end++;
	    this.sub.push_back(next);
	}
    }
    void print() {
	for(auto& expr : self.sub) {
	    putchar("(");
	    for(char* pos = start; pos != end; ++pos)
		putchar(*pos);
	    putchar(")");
	}
    }
}

int main() {
    Expr e;
    const char* str = "(a (b c d))";
    cc = str;
    e.parse(cc);
    return 0;
}
