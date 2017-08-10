#include <iostream>

class Hello {
public:
    int times;
    Hello(int times) : times(times) {}
    template <typename T>
    void print(T value) {
        for(int i=0; i<times; ++i) {
            std::cout << value << "\n";
        }
    }
};

int main() {
    Hello h {2};
    h.print("cool");
    h.print(11);
    return 0;
}
