#include <iostream>
#include <cstdio>

using namespace std;

bool isLeap(int i);

int main()
{
    int a, b;
    bool flag = false;
    while (cin >> a >> b, a || b) {
        bool fl = false;
        if (flag) {
            puts("");
        } else {
            flag = true;
        }
        for (int i = a; i <= b; i++) {
            if (isLeap(i)) {
                fl = true;
                cout << i << '\n';
            }
        }
        if (!fl) {
            puts("NA");
        }
    }
    return 0;
}

bool isLeap(int i)
{
    if (!(i % 400) ) {
        return true;
    } else if (!(i % 100) ) {
        return false;
    } else if (!(i % 4) ) {
        return true;
    } else {
        return false;
    }
}
