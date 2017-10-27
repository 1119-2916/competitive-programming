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
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);
    while (n) {
        vector<string> data(n);
        rep(i, n) {
            string tmp;
            cin >> tmp;
            data[i].pb(tmp[0]);
            rep(j, tmp.length()-1) {
                if (tmp[j] == 'a' || tmp[j] == 'i' || tmp[j] == 'u' || 
                        tmp[j] == 'e' || tmp[j] == 'o') {
                    data[i].pb(tmp[j+1]);
                }
            }
        }
        bool out = false;
        Rep(k, 51) {
            bool fl = true;
            set<string> s;
            rep(i, n) {
                if (s.find(data[i].substr(0, k)) != s.end()) {
                    fl = false;
                    break;
                } else {
                    s.insert(data[i].substr(0, k));
                }
            }
            if (fl) {
                cout << k << endl;
                out = true;
                break;
            }
        }
        if (!out) {
            cout << -1 << endl;
        }
        cin >> n;
    }
    return 0;
}

