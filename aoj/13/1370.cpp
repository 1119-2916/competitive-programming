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

vi sub(vi &a, vi &b)
{
    vi ret(a.size(), 0);
    rep(i, ret.size()) {
        ret[i] = b[i] - a[i];
    }
    return ret;
}

void dump(vi p)
{
    cout << "p = {";
    rep(i, p.size()) {
        cout << p[i] << ", ";
    }
    cout << "}" << endl;
}

int solve(vvi &yui, vvi &kyoko, int p)
{
    set<vi> st;
    for (int i = 0; i + p < yui.size(); i++) {
        st.insert(sub(yui[i], yui[i+p]));
    }

    for (int i = 0; i + p < kyoko.size(); i++) {
        if (st.find(sub(kyoko[i], kyoko[i+p])) != st.end()) {
            dump(sub(kyoko[i], kyoko[i+p]));
            return p;
        }
    }

    return 0;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string momo;
    cin >> momo;
    string shami;
    cin >> shami;

    vvi yui(momo.size()+1, vi(26, 0)), kyoko(shami.size()+1, vi(26, 0));
    rep(i, momo.size()) {
        rep(j, yui[i].size()) {
            yui[i+1][j] = yui[i][j];
        }
        yui[i+1][momo[i] - 'a']++;
    }
    rep(i, shami.size()) {
        rep(j, kyoko[i].size()) {
            kyoko[i+1][j] = kyoko[i][j];
        }
        kyoko[i+1][shami[i] - 'a']++;
    }
    
    int n = min(momo.size(), shami.size());

    int ans = 0;
    Rep(i, n+1) {
        ans = max(ans, solve(yui, kyoko, i));
    }

    cout << ans << endl;

    return 0;
}
