#include <stdio.h>
#include <stdint.h>
#include <array>

struct Mixer {
    char bpm, tickrate;
};

namespace command {
    class Command {
        char id, data;
        void exec(Mixer& m) {
            switch(id) {
            case '2': if (data < 32) m.tickrate = data; else m.bpm = data;
            default: fprintf(stderr, "invalid command!");
            }
        }
        std::array<char, 3> to_chars() {
            std::array<char, 3> out = {0};
            sprintf(&out[0], "%c%X", id, data);
            return out;
        }
        void print() {
            printf("%c%X", id, data);
        }
    };
}
