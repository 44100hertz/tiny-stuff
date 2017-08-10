#include <cstdio>

int main()
{
    class Fns {
    public:
        void printint(int a) { std::printf("%d\n", a); }
    };
    auto fns = Fns {};

    fns.printint(8);
}
