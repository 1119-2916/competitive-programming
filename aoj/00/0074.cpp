#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++) 

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c, a != -1) {
        int time = (a * 60 + b ) * 60 + c;
        time = (120 * 60) - time;
        a = time/3600;
        b = (time - a*3600)/60;
        c = time - a * 3600 - b * 60;
        cout << "0" << a << ":";
        if (b < 10) {
            cout << "0" << b << ":";
        } else {
            cout << b << ":";
        }
        if (c < 10) {
            cout << "0" << c << endl;
        } else {
            cout << c << endl;
        }
        time *= 3;
        a = time/3600;
        b = (time - a*3600)/60;
        c = time - a * 3600 - b * 60;
        cout << "0" << a << ":";
        if (b < 10) {
            cout << "0" << b << ":";
        } else {
            cout << b << ":";
        }
        if (c < 10) {
            cout << "0" << c << endl;
        } else {
            cout << c << endl;
        }
    }
    return 0;
}
