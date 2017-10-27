#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++) 
#define INF 1010001000

typedef pair<int, int> i_i;

int dijk(int st, int en, vector<vector<int> > &g);

int n, m;

int main()
{
    while (cin >> n >> m, (n|m)) {
        vector<vector<int> > g(n+1, vector<int>(n+1, INF));
        loop(i, m) {
            int cmd;
            cin >> cmd;
            if (cmd) {
                int a, b, c;
                cin >> a >> b >> c;
                g[a][b] = min(g[a][b], c);
                g[b][a] = min(g[a][b], c);
            } else {
                int a, b;
                cin >> a >> b;
                int ans = dijk(a, b, g);
                cout << ((ans != INF) ? ans : -1) << endl;
            }
        }
    }
    return 0;
}

int dijk(int st, int en, vector<vector<int> > &g)
{
    priority_queue<i_i, vector<i_i>, greater<i_i> > pq;
    vector<int> ans(n+1, INF);
    ans[st] = 0;
    pq.push(i_i(0, st));
    while (!pq.empty()) {
        i_i tmp = pq.top(); pq.pop();
        //cout << tmp.second << endl;
        for (int i = 1; i < n+1; i++) {
            if (ans[i] > tmp.first + g[tmp.second][i]) {
                ans[i] = tmp.first + g[tmp.second][i];
                pq.push(i_i(ans[i], i));
                //cout << ans[i] << " " << i << endl;
            }
        }
    }
    return ans[en];
}

