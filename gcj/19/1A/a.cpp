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

string f(string s)
{
    string ret = "";
    if (s == "" || s.size() == 1) return "";
    rep(i, (int)s.size()-1) {
        ret += s[i];
    }
    return ret;
}

int solve()
{
    Int(n);
    vector<string> data(n);
    rep(i, n) {
        cin >> data[i];
        reverse(all(data[i]));
    }
    sort(all(data));

    int ans = 0;
    do {
        string bef;
        int ret = 0;
        for (int i = 1; i < n; i += 2) {
            string yui = "";
            for (int j = 0; j < min(data[i].size(), data[i-1].size()); j++) {
                if (data[i][j] == data[i-1][j]) yui += data[i][j];
                else break;
            }
            //cout << "yui : " << yui << endl;
            if (yui == bef) {
                yui = f(yui);
            }
            if (yui == "") {
                break;
            }
            bef = yui;
            ret += 2;
        }
        ans = max(ans, ret);
    } while (next_permutation(all(data)));

    return ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(T);
    for (int i = 0; i < T; i++) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }

    return 0;
}
