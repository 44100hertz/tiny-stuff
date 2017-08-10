#include <iostream>

template <typename T>
constexpr T int_or_float(bool is_float) {
    float a = 0.5;
    int b = 5;
    if constexpr (is_float)
        return a;
    else
        return b;
}


int main() {
    float x = int_or_float(true);
    int y = int_or_float(false);

    std::cout << x << " " << y << "\n";
    return 0;
}
