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
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

char data[3][300];
int p[3];
int dp[251][251][251];

int next(vi &targ, int p)
{
    auto ret = lower_bound(all(targ), p);
    if (ret == targ.end()) return INF;
    else return *ret+1;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, q);

    string st;
    cin >> st;

    vvi pos('z' - 'a' + 1);
    rep(i, st.size()) {
        pos[st[i]-'a'].pb(i);
    }
    rep(i, pos.size()) pos[i].pb(INF);

    rep(i, q) {
        string cmd; cin >> cmd;
        Int(bm);
        if (cmd[0] == '+') {
            string ch; cin >> ch;
            data[bm-1][p[bm-1]] = ch[0];
            p[bm-1]++;

            if (bm == 1) {
                int x = p[bm-1];
                rep(j, p[1]+1) {
                    rep(k, p[2]+1) {
                        dp[x][j][k] = next(pos[data[0][x-1]-'a'], dp[x-1][j][k]);
                        if (j != 0) dp[x][j][k] = min(dp[x][j][k], next(pos[data[1][j-1]-'a'], dp[x][j-1][k])); 
                        if (k != 0) dp[x][j][k] = min(dp[x][j][k], next(pos[data[2][k-1]-'a'], dp[x][j][k-1]));
                    }
                }
            } else if (bm == 2) {
                int x = p[bm-1];
                rep(j, p[0]+1) {
                    rep(k, p[2]+1) {
                        dp[j][x][k] = next(pos[data[1][x-1]-'a'], dp[j][x-1][k]);
                        if (j != 0) dp[j][x][k] = min(dp[j][x][k], next(pos[data[0][j-1]-'a'], dp[j-1][x][k]));
                        if (k != 0) dp[j][x][k] = min(dp[j][x][k], next(pos[data[2][k-1]-'a'], dp[j][x][k-1]));
                    }
                }
            } else {
                int x = p[bm-1];
                rep(j, p[0]+1) {
                    rep(k, p[1]+1) {
                        dp[j][k][x] = next(pos[data[2][x-1]-'a'], dp[j][k][x-1]);
                        if (j != 0) dp[j][k][x] = min(dp[j][k][x], next(pos[data[0][j-1]-'a'], dp[j-1][k][x]));
                        if (k != 0) dp[j][k][x] = min(dp[j][k][x], next(pos[data[1][k-1]-'a'], dp[j][k-1][x]));
                    }
                }
            }

        } else {
            p[bm-1]--;
        }


        /*
        rep(j, n+1) {
            cout << j << " : " << endl;
            rep(k, n+1) {
                rep(l, n+1) cout << dp[j][k][l] << " ";
                cout << endl;
            }
        }
        */

        if (dp[p[0]][p[1]][p[2]] < INF) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
