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

bool check(string st, int s, int t)
{
    int p = 0;
    for (int i = s; i <= t; i++) {
        if (st[i] == '(') p++;
        else p--;
        if (p < 0) return false;
    }
    if (p == 0) return true;
    else return false;
}

int solve(string st)
{
    int ans = 0;
    rep(i, st.size()) {
        for (int j = i+1; j < st.size(); j++) {
            if (check(st, i, j)) ans++;
        }
    }
    return ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string st;
    while ( cin >> st ) {

        map<int, int> cnt;
        int ans = 0, pos = 0;
        rep(i, st.size()) {
            if (st[i] == '(') {
                pos++;
                cnt[pos]++;
            } else {
                ans += cnt[pos];
                cnt[pos+1] = 0;
                pos--;
                if (pos < 0) {
                    pos = 0;
                }
            }
        }
        std::cout << ans << std::endl;
        /*
        int  tmp = solve(st);
        if (tmp != ans) {
            cout << "=================" << endl;
            std::cout << st << std::endl;
            cout << "=================" << endl;
        }
        */
    }


    return 0;
}
