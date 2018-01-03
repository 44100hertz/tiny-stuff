#include <iostream>
#include <variant>
using namespace std;

int main() {
    variant<int, float> thing;

    thing = 100;
    int a = get<int>(thing);
    int f = get<float>(thing);

    cout << a << " " << f << endl;

    return 0;
}
