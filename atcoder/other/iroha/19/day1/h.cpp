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

    string st;
    cin >> st;

    int cnt = 0;
    rep(i, st.size()) {
        cnt += st[i] - '0';
    }

    string ans = "";
    while (cnt) {
        if (cnt >= 9) {
            ans.pb('9');
            cnt -= 9;
        } else {
            ans.pb(cnt + '0');
            cnt = 0;
        }
    }
    reverse(all(ans));
    if (st == ans) {
        bool fl = true;
        Rep(i, ans.size()) {
            if (ans[i] != '9') fl = false;
        }
        if (fl && ans[0] != '9') {
            if (ans.size() != 1) {
                ans[1]--;
                ans[0]++;
            } else {
                cout << "1";
                ans[0]--;
            }
        } else if (fl) {
            cout << "1";
            ans[0]--;
        } else {
            int p = -1;
            rep(i, ans.size()) {
                if (ans[i] != '0') {
                    ans[i]--;
                    p = i;
                    break;
                }
            }
            for (int i = ans.size()-1; i >= 0; i--) {
                if (i != p && ans[i] != '9') {
                    ans[i]++;
                    break;
                }
            }
        }
    }
    rep(i, ans.size()) {
        cout << (char)ans[i];
    }
    cout << endl;

    

    return 0;
}
