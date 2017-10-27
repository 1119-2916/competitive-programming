#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX 1010001000

using namespace std;

int main()
{
    int a, b;
    string str;
    bool c = false, f = false;

    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (c == false && str[i] == 'C') {
            c = true;
        } else if (c && str[i] == 'F') {
            f = true;
        }
    }

    if (c && f) {
        cout << "Yes" << endl;
    } else {
        cout << "No" <<endl;
    }

    return 0;
}
