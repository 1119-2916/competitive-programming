#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-10
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
#define Int(x) int x; scanf("%d", &x);
#define int2(x, y) int x, y; scanf("%d %d", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

class JumpDistancesOnTreeEasy
{
    public:
        /*
        vp yui;
        vvi tree;
        int cha()
        {
            vi dt;
            rep(i, tree[0].size()) {
                dt.pb(haba(i, 1));
            }
            sort(all(dt));
            if (dt.size() >= 2) {
                return dt[dt.size()-1] + dt[dt.size()-2];
            } else {
                return dt[0];
            }
        }
        int haba(int pos, int cost)
        {
            int ret = cost;
            if (tree[pos].size()) {
                rep(i, tree[pos].size()) {
                    ret = dfs(tree[pos][i], cost+1);
                }
            }
            return ret;
        }
        int dfs(int pos, int cost)
        {
            int ret = cost;
            if (tree[pos].size()) {
                rep(i, tree[pos].size()) {
                    ret = dfs(tree[pos][i], cost+1);
                }
            } else {
                yui.pb(i_i(cost, pos));
            }
            return ret;
        }
        string isPossible(vector <int> p, vector <int> S)
        {
            tree = vvi(p.size()+1);
            rep(i, p.size()) {
                tree[p[i]].pb(i+1);
            }
            dfs(0, 0);

            vb dp(51, false);
            dp[0] = true;
            rep(i, S.size()) {
                rep(j, 51 - S[i]) {
                    if (dp[j]) {
                        dp[j + S[i]] = true;
                    }
                }
            }
            int aaaa = cha();
            rep(i, S.size()) {
                if (aaaa < S[i]) {
                    return "Impossible";
                }
            }
            bool ans = true;
            vb used(S.size(), false);
            rep(i, yui.size()) {
                if (!dp[yui[i].fir]) {
                    ans = false;
                    break;
                }
            }
            if (ans) {
                return "Possible";
            } else {
                return "Impossible";
            }

        }
*/

};

 
signed main()
{
    JumpDistancesOnTreeEasy kyoko;
    Int(n);
    vi data(n);
    rep(i, n) {
        cin >> data[i];
    }
    Int(m);
    vi state(m);
    rep(i, m) {
        cin >> state[i];
    }
    cout << kyoko.isPossible(data, state) << endl;
    return 0;
}

