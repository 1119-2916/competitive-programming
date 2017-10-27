#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define pb push_back 

int bfs(int s, int t, int c);

vector<vector<int> > g(100001);

int main()
{
    int n;
    cin >> n;
    loop(i, n) {
        int r, k, t;
        cin >> r >> k;
        loop(j, k) {
            cin >> t;
            g[r].pb(t);
        }
    }
    int p;
    cin >> p;
    loop (i, p) {
        int s, d, v;
        cin >> s >> d >> v;
        int ans = bfs(s, d, v);
        if (ans != -1) {
            cout << v-ans << endl;
        } else {
            cout << "NA" << endl;
        }
    }
    return 0;
}

int bfs(int s, int t, int c)
{
    vector<bool> check(100001, false);
    queue<int> fq, nq, sq;
    int cnt = 0;
    fq.push(s);
    if (c == 0) {
        return -1;
    }
    while (1) {
        c--;
        while (!fq.empty()) {
            int pos = fq.front(); fq.pop();
            if (check[pos]) {
                continue;
            } else {
                check[pos] = true;
            }
            //cout << pos << endl;
            if (pos == t) {
                return c;
            }
            for (int i: g[pos]) {
                nq.push(i);
            }
        }
        if (c == 0 || nq.empty()) {
            return -1;
        }
        fq = nq;
        nq = sq;
        //cout << c << "====" << endl;
    }
}


