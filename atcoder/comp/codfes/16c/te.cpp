#include <iostream>

using namespace std;

int main()
{
    long long int a;
    int b, c;

    b = 1010001000;
    c = 1010001000;

    a = 1010001000;

    a *= b;

    a %= 1010000999;

    cout << a << endl;

    return 0;
}
