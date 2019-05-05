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

//bool solve(vi &data)



signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);

    vector<vvi> table(n+1, vvi(n+1, vi(n+1, 0)));

    table[0][0][0] = 10;
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                if (!i && !j && !k) continue;
                bool ret = false;
                if (i && j) {
                    if (table[i-1][j-1][k] == -1) ret = true;
                }
                if (j && k) {
                    if (table[i][j-1][k-1] == -1) ret = true;
                }
                if (i && k) {
                    if (table[i-1][j][k-1] == -1) ret = true;
                }
                if (i && j && k) {
                    if (table[i-1][j-1][k-1] == -1) ret = true;
                }
                if (ret) table[i][j][k] = 10;
                else table[i][j][k] = -1;
            }
        }
    }

    rep(i, n+1) {
        cout << i << " : " << endl;
        rep(j, n+1) {
            rep(k, n+1) {
                cout << table[i][j][k] << " ";
            }cout << endl;
        }
    }
    

    return 0;
}
