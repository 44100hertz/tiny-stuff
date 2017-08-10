#include <stdio.h>
#include <string.h>
#include <vector>
#include <cstdint>

#define char uint8_t

template <typename T>
struct CharTab {
    T data[256];
public:
    CharTab(T with) { for(auto& d : data) { d = with; } }
    CharTab range(char from, char to, T start) {
        for(char i=from; i<to; ++i) {
            data[i] = start;
            start++;
        }
        return *this;
    }
    CharTab alias(std::vector<char> from, char to) {
        for(auto c : from) {
            data[c] = data[to];
        }
        return *this;
    }
    T operator[](unsigned long i) {
        return data[i];
    }
};

int main() {
    auto base32 = CharTab<char>(0)
        .range('a', 'z', 'A')
        .range('A', 'Z', 'A')
        .range('0', '9', '0')
        .alias({'O', 'o'}, '0')
        .alias({'I', 'l', 'i'}, '1')
        .alias({'S', ''});

    printf("%c\n", base32['a']);
    printf("%c\n", base32['A']);
    printf("%c\n", base32['0']);
    printf("%c\n", base32['O']);
    printf("%c\n", base32['I']);
}



