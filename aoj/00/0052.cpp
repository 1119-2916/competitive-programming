#include <iostream>
#include <cstdio>

using namespace std;

int mod5(int a);

int main()
{
    int n;

    while (cin >> n, n) {
        int ans = 0;
        for (int i = 5; i <= n; i++) {
            ans += mod5(i);
        }
        cout << ans << endl;
    }

    return 0;
}

int mod5(int a)
{
    int ret = 0;

    while (!(a % 5)) {
        ret++;
        a /= 5;
    }

    return ret;
}
