#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define INF 1010001000
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef pair<int, int> i_i;
typedef long long int llong;
typedef pair<llong, llong> ll_ll;
typedef struct edge {int f, t;}Edge;


int main()
{
    int r, w, c, n, ans;
    while (cin >> r >> w >> c >> n, r) {
        ans = (c * w - r) / n;
        if (ans <= 0) {
            cout << 0 << endl;
        } else if ((c * w - r) % n) {
            ans++;
            cout << ans << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
