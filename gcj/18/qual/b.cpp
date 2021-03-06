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

int calc(string st)
{
    int ret = 0;
    int dam = 1;
    rep(i, st.size()) {
        if (st[i] == 'C') {
            dam *= 2;
        } else if (st[i] == 'S') {
            ret += dam;
        }
    }
    return ret;
}

void solve(int n, vi &data)
{
    vi yui(0), kyoko(0);
    rep(i, n) {
        if (i % 2) kyoko.pb(data[i]);
        else yui.pb(data[i]);
    }
    sort(all(yui));
    sort(all(kyoko));
    vi ans(0);
    rep(i, kyoko.size()) {
        ans.pb(yui[i]);
        ans.pb(kyoko[i]);
    }
    if (yui.size() != kyoko.size()) ans.pb(yui.back());

    rep(i, n-1) {
        if (ans[i] > ans[i+1]) {
            cout << i << endl;
            return ;
        }
    }
    cout << "OK" << endl;
}

void test()
{
    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n; i++) cin >> data[i];
    solve(n, data);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    //test(); return 0;

    Int(t);
    for (int _ = 1; _ <= t; _++) {
        cout << "Case #" << _ << ": ";
        Int(n);
        vector<int> data(n);
        for (int i = 0; i < n; i++) cin >> data[i];
        solve(n, data);
    }

    return 0;
}






