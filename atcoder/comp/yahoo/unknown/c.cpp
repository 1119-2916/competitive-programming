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
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<string> data(n);
    vi use(k);
    vb uf(n, false);
    rep(i, k) {
        cin >> use[i];
        use[i]--;
        uf[use[i]] = true;
    }
    rep(i, n) {
        cin >> data[i];
    }
    string longest = "", shortest = data[use[0]];

    if (n == k) {
        return 0;
    }
    rep(i, k) {
        if (data[use[i]].size() > longest.size()) {
            longest = data[use[i]];
        }
        if (data[use[i]].size() < shortest.size()) {
            shortest = data[use[i]];
        }
    }
    string ans = "";
    for (int i = 1; i <= longest.size(); i++) {
        string tmp = longest.substr(0, i);
        bool flag = true;
        rep(j, n) {
            if (uf[j]) {
                if (tmp != data[j].substr(0, i)) {
                    flag = false;
                    break;
                }
            } else {
                if (tmp == data[j].substr(0, i)) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << tmp << endl;
            return 0;
        }
    }
    cout << -1 << endl;







    return 0;
}

