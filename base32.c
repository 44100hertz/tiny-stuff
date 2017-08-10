//#include <stdio.h>

char from_char(char c) {
    const char lut[256] = {
        ['O'] = '0', ['o'] = '0',
        ['I'] = '1', ['l'] = '1', ['i'] = '1',
        ['Z'] = '2', ['z'] = '2',
        ['S'] = '5', ['s'] = '5',
    };
    if(lut[c]) c = lut[c];
    if(c >= 'a' && c <= 'z') c -= 'a' - 'A';
    return c;
}
