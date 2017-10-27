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
 
bool wrong(string s);

signed main()
{
    Int(cs);
    rep(loop, cs) {

        string s;
        cin >> s;

        cout << "Case #" << loop + 1 << ": ";

        while (wrong(s)) {
            Rep(i, s.size()) {
                if (s[i-1] > s[i]) {
                    s[i-1]--;
                    for (; i < s.size(); i++) {
                        s[i] = '9';
                    }
                }
            }
        }

        rep(i, s.size()) {
            if (s[i] != '0') {
                for (; i < s.size(); i++) {
                    printf("%c", s[i]);
                }
                cout << endl;
            }
        }
    }

    return 0;
}

bool wrong(string s)
{
    rep(i, s.size()) {
        if (s[i] != '0') {
            for (; i < s.size()-1; i++) {
                if (s[i] > s[i+1]) {
                    return true;
                }
            }
        }
    }
    return false;
}

