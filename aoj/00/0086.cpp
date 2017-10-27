#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define loop(i, n) for (int i = 3; i <= n; i++)

int main()
{
    int a, b;
    while (cin >> a >> b) {
        vector<int> data(101, 0);
        while (a != 0) {
            data[a]++;
            data[b]++;
            cin >> a >> b;
        }
        bool fl = true;
        if (!(data[1] % 2)) fl = false;
        if (!(data[2] % 2)) fl = false;
        loop(i, 100) {
            if (data[i] % 2) {
                fl = false;
            }
        }
        if (fl) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
    }
    return 0;
}
