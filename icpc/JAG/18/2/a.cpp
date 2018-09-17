#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    int num = c;
    while (1) {
        if (num % 17 == a && num % 107 == b) {
            cout << num << endl;
            return 0;
        }
        num += 1000000007;
    }

    return 0;
}


