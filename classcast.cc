#include <iostream>

class A {
public:
    const char* word;
    virtual void barf() = 0;
    virtual ~A() {};
};

class B : public A {
public:
    B(const char* word = "") { this->word = word; }
    void barf() { std::cout << word; }
};

int main() {
    B b = {"hello,"};
    B ab = B{"world.\n"};
    A& a = ab;

    b.barf();
    a.barf();
}
