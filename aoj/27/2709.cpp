#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);
    int2(m, k);
    vi state(n, -1);
    vi room(m);
    rep(i, m) {
        cin >> room[i];
        room[i]--;
        state[room[i]] = i;
    }

    vvi graph(n, vi(k, 0));
    rep(i, n) {
        rep(j, k) {
            cin >> graph[i][j];
            graph[i][j]--;
        }
    }

    vi dp((1 << m), INF);
    dp[(1 << m)-1] = 0;
    queue<int> que;
    que.push((1<<m)-1);
    while (dp[0] == INF) {
        int tmp = que.front();
        que.pop();
        //cout << tmp << ":" << endl;
        rep(i, k) {
            int nxt = 0;
            rep(j, m) {
                if (tmp & (1 << j)) {
                    int ikisaki = graph[room[j]][i];
                    if (state[ikisaki] != -1) {
                        //cout << state[ikisaki] << " ";
                        nxt |= (1 << state[ikisaki]);
                    }
                }
            }
            //cout << nxt << " ";
            if (dp[nxt] > dp[tmp]+1) {
                dp[nxt] = dp[tmp] + 1;
                que.push(nxt);
            }
        }
        //cout << endl;
    }
    cout << dp[0] << endl;

    return 0;
}

