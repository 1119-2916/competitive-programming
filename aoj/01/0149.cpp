#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int data[8] = {0};
    double a, b;
    while (cin >> a >> b) {
        if (a >= 1.1) {
            data[0]++;
        } else if (a >= 0.6) {
            data[2]++;
        } else if (a >= 0.2) {
            data[4]++;
        } else {
            data[6]++;
        }
        if (b >= 1.1) {
            data[1]++;
        } else if (b >= 0.6) {
            data[3]++;
        } else if (b >= 0.2) {
            data[5]++;
        } else {
            data[7]++;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (i%2) {
            cout << data[i] << endl;
        } else {
            cout << data[i] << " ";
        }
    }
    return 0;
}
