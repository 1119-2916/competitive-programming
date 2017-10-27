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
    int n;
    while (cin >> n, n) {
        vector<vector<bool> > key(n+1, vector<bool>(n+1, false));
        rep(i, n) {
            int k;
            cin >> k;
            rep(j, k) {
                int a;
                cin >> a;
                key[i+1][a] = true;
            }
        }
        int k;
        cin >> k;
        vector<bool> ch(n+1, true);
        rep(i, k) {
            int a;
            cin >> a;
            rep(j, n+1) {
                if (!(key[j][a] && ch[j])) {
                    ch[j] = false;
                }
            }
        }
        int ret = 0;
        rep(i, n+1) {
            if (ch[i] && !ret) {
                ret = i;
            } else if (ch[i] && ret) {
                ret = -1;
            }
        }
        if (!ret) {
            ret = -1;
        }
        cout << ret << endl;
    }

    return 0;
}
