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
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

string bitst(int a)
{
    string st;
    if (!a) return "0";
    while (a) {
        st.pb((a % 2) + '0');
        a /= 2;
    }
    reverse(all(st));
    return st;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n); int3(x, y, z);
    int toshino = (1 << (x - 1));
    toshino = (toshino << y) + (1 << (y - 1));
    toshino = (toshino << z) + (1 << (z - 1));
    int mask = (1 << (x + y + z)) - 1;

    vvi funami(n+1, vi(1 << 17, 0));
    funami[0][0] = 1;

    rep(i, n) {
        rep(j, 1 << (x + y + z)) {
            Rep(k, 11) {
                int tmp = ((j << k) + (1 << (k-1))) & mask;
                if ((tmp & toshino) != toshino) {
                    funami[i+1][tmp] = 
                        (funami[i+1][tmp] + funami[i][j]) % MOD;
                }
            }
        }
    }

    int ans = 1;
    rep(i, n) 
        ans = (ans * 10) % MOD;
    rep(i, funami[n].size())
        if (i != toshino) ans = (ans - funami[n][i] + MOD) % MOD;

    cout << ans << endl;

    return 0;
}

