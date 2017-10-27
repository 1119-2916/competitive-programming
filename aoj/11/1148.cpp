#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

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
    int n, m;
    while (cin >> n >> m, n) {
        int r;
        cin >> r;
        vector<vector<int> > solve(m+1, vector<int>(1261, 0));
        rep(i, r) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (d) {
                solve[c][a]++;
            } else {
                solve[c][a]--;
            }
        }
        for (int j = 1; j <= m; j++) {
            for (int i = 540; i < 1260; i++) {
                solve[j][i+1] += solve[j][i];
            }
        }
        int q;
        cin >> q;
        rep(i, q) {
            int a, b, c;
            cin >> a >> b >> c;
            int ret = 0;
            for (int j = a; j < b; j++) {
                if (solve[c][j]) {
                    ret++;
                }
            }
            cout << ret << endl;
        }
    }
    return 0;
}
