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

int state[200][200];

int funami(int n, int m, int pos)
{
//    cout << "call : " << n << " " << m << " " << state[n][m] << endl;
    if (state[n][m]) return state[n][m];

    if (n == 0 && m == 0) return state[n][m] = -pos;
    if (n == m) return state[n][m] = pos;
    if (!n || !m) return state[n][m] = pos;

    bool fl = false;
    rep(i, n) {
        fl |= funami(i, m, -pos) == pos;
    }
    rep(i, m) {
        fl |= funami(n, i, -pos) == pos;
    }
    Rep(i, min(n, m) + 1) {
        fl |= funami(n-i, m-i, -pos) == pos;
    }
    if (fl) {
        return state[n][m] = pos;
    } else {
        return state[n][m] = -pos;
    }
}

void mmm(void)
{
    rep(i, 200) {
        rep(j, 200) {
            state[i][j] = 0;
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(a, b);
    vvi ans(a+1, vi(b+1, 0));

    rep(i, a+1) {
        rep(j, b+1) {
            //memset(state, 0, sizeof(state));
            mmm();
            funami(i, j, 1);
            ans[i][j] = state[i][j];
        }
    }

    rep(i, a) {
        rep(j, b) {
            cout << (ans[i][j] == 1 ? 1 : 0) << " ";
        }
        cout << endl;
    }


    return 0;
}



