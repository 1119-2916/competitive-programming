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

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, q);
    vi table(n+1, 0);
    string st;
    cin >> st;
    

    int state = 0;
    rep(i, st.size()) {
        if (st[i] == 'A') {
            state = 1;
        } else if (state == 1 && st[i] == 'C') {
            table[i+1] = 1;
            state = 0;
        } else {
            state = 0;
        }
    }

    Rep(i, table.size()) {
        table[i] += table[i-1];
    }

//    rep(i, table.size()) cout << table[i] << " "; cout << endl;

    while (q--) {
        int2(a, b);
        int yui = 0;
        if (a > 1 && st[a-1] == 'C' && st[a-2] == 'A') yui = 1;
        cout << table[b] - table[a-1] - yui << endl;
    }



    return 0;
}
