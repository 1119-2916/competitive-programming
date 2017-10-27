#include <iostream>
using namespace std;
int main()
{
    int n, x, a, b, ans = 0;
    cin >> n >> x >> a >> b;
    for (int i = 1; i < n; i++, a = b - tmp, cin >> b) {
        int res = max(0, (a+b)-x), tmp = min(b, res);
        ans += tmp + max(0, res-b);
    }
    cout << ans << endl;

    return 0;
}

