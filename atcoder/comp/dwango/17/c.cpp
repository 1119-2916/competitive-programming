#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define INF 1010001000
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back


int main()
{
    int n;
    cin >> n;

    int a = 0, b = 0, c = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            a++;
        } else if (tmp == 2) {
            b++;
        } else if (tmp == 3) {
            c++;
        } else if (tmp == 4) {
            ans++;
        }
    }

    ans += c;
    a -= c;

    ans += b / 2;

    if (b % 2) {
        ans++;
        a -= 2;
    }

    if (a > 0) {
        ans += a / 4;
        if (a % 4) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

    
