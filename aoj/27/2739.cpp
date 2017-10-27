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
    int n, m, t;
    cin >> n >> m >> t;
    vector<bool> time(t, true);
    m++;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        rep(i, m) {
            if (tmp + i <= t) {
                time[tmp + i - 1] = false;
            }
            if (0 <= tmp - i) {
                time[tmp - i] = false;
            }
        }
    }
    int ret = 0;
    rep(i, t) {
        if (time[i]) {
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}
