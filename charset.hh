//#include <stdio.h>

namespace charset {
    class Charset {
    public:
        unsigned char c[256] = {0};
        char operator[](unsigned char i) const { return c[i]; }
        bool contains(unsigned char i) const { return c[i] == i; }
        bool valid(unsigned char i) const { return c[i] != 0; }
    };

    class Base32 : public Charset {
    public:
        Base32() {
            for(int i=0; i<256; ++i) {
                if(i >= 'a' && i <= 'z')
                    c[i] = i + 'A' - 'a';
                else if((i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
                    c[i] = i;
            };
            const char remaps[] = "O0o0I1i1Z2z2S5s5";
            for(int i=0; i<sizeof(remaps); i+=2) { c[i] = remaps[i+1]; }
        }
    } base32;

    class Hex : public Charset {
    public:
        Hex() {
            for(int i=0; i<256; ++i) {
                if(i >= 'a' && i <= 'f')
                    c[i] = i + 'A' - 'a';
                else if((i >= 'A' && i <= 'F') || (i >= '0' && i <= '9'))
                    c[i] = i;
            }
        }
    } hex;
}
