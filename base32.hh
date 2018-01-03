//#include <stdio.h>

class Charset {
    virtual char operator[](unsigned char i) = 0;
    virtual bool contains(unsigned char i) = 0;
    virtual bool valid(unsigned char i) = 0;
};

class Base32 : public Charset {
    unsigned char c[256] = {0};
public:
    Base32() {
        for(int i=0; i<256; ++i) {
            if(i >= 'a' && i <= 'z')
                c[i] = i + 'A' - 'a';
            else if((i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
                c[i] = i;
            else
                c[i] = 0;
        };
        c['O'] = '0'; c['o'] = '0';
        c['I'] = '1'; c['l'] = '1'; c['i'] = '1';
        c['Z'] = '2'; c['z'] = '2';
        c['S'] = '5'; c['s'] = '5';
    }
    char operator[](unsigned char i) {
        return c[i] ? c[i] : i;
    }
    bool contains(unsigned char i) {
        return c[i] == i;
    }
    bool valid(unsigned char i) {
        return c[i] != 0;
    }
};

