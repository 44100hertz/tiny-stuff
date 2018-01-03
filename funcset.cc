#include <stdio.h>

struct A {
    virtual void fart() = 0;
};

struct B : public A {
    void fart() { puts("ok"); }
};

struct C : public A {
    void fart() { puts("not OK!"); }
};

int main() {
    A* b = new B;
    b->fart();
    A* c = new C;
    *b = *c;
    b->fart();
    return 0;
}
