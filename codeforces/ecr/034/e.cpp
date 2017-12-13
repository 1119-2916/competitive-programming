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

bool isok(string a, string b)
{
    if (a.size() != b.size()) return false;
    vb used(26, false);
    bool tyofuku = false;
    rep(i, b.size()) {
        if (used[b[i] - 'a']) tyofuku = true;
        used[b[i] - 'a'] = true;
    }
    int cnt = 0;
    rep(i, a.size()) {
        if (a[i] != b[i]) cnt++;
    }
    if (cnt == 2 || cnt == 0 && tyofuku) {
        return true;
    } else {
        return false;
    }
}

int diffst(string a, string b)
{
    if (a.size() != b.size()) return -INF;
    int ret = 0;
    rep(i, a.size()) {
        if (a[i] != b[i]) ret++;
    }
    return ret;
}

bool col(string a, string b, string &out)
{
    rep(i, a.size()) {
        if (a[i] == b[i]) {
            if (out[i] == '?') {
                out[i] = a[i];
            } else if (out[i] != a[i]) {
                return false;
            }
        }
    }
    return true;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, len);
    vector<string> input(0);
    rep(i, n) {
        string st;
        cin >> st;
        bool ok = true;
        rep(j, input.size()) {
            if (st == input[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            input.pb(st);
        }
    }
    n = input.size();
    if (n == 1) {
        cout << input[0][1] << input[0][0];
        for (int i = 2; i < input[0].size(); i++) {
            cout << input[0][i];
        }
        cout << endl;
        return 0;
    }
    string ans = "";
    rep(i, len) ans.pb('?');
    rep(i, n) {
        rep(j, i) {
            int tmp = diffst(input[i], input[j]);
            if (tmp >= 5) {
                cout << -1 << endl;
                return 0;
            } else if (3 <= tmp && tmp <= 4) {
                if (!col(input[i], input[j], ans)) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    string sup = "";
    rep(i, input[0].size()) {
        if (ans[i] == '?') {
            sup.pb(input[0][i]);
        }
    }
    if (sup.size() > 4) {
        cout << -1 << endl;
        return 0;
    }

    sort(all(sup));
    do {
        string funami = "";
        int ptr = 0;
        rep(i, ans.size()) {
            if (ans[i] == '?') {
                funami.pb(sup[ptr++]);
            } else {
                funami.pb(ans[i]);
            }
        }

        bool ok = true;
        rep(i, input.size()) {
            ok &= isok(input[i], funami);
        }
        if (ok) {
            cout << funami << endl;
            return 0;
        }
    } while (next_permutation(all(sup)));
    cout << -1 << endl;







    return 0;
}
