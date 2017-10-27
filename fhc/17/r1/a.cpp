#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
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

signed main()
{
    int t;
    cin >> t;
    rep(data, t) {
        cout << "Case #" << data + 1 << ": ";
        int n, m;
        cin >> n >> m;
        priority_queue<llong> que;
        llong ret = 0;
        rep(i, n) {
            vector<llong> tmp(m);
            rep(j, m) {
                cin >> tmp[j];
            }
            sort(tmp.begin(), tmp.end());
            llong tax = 0;
            rep(j, m) {
                llong ntax = pow((double)(j+1), 2.0);
                tmp[j] += ntax - tax;
                tax = ntax;
                que.push(-tmp[j]);
            }
            ret -= que.top();
            que.pop();
        }
        cout << ret << endl;
    }
    return 0;
}
