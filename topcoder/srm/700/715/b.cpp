#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-10
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
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

class MaximumRangeDiv2 {

    public:

        int findMax(string s) {

            /*
            int ans = 0;
            rep(ptr, s.size()+1) {
                int num = 0, mi = 0, ma = 0;
                rep(i, s.size()) {
                    if (i < ptr && s[i] == '+') {
                        num++;
                        mi = min(mi, num);
                        ma = max(ma, num);
                    } else if (i >= ptr && s[i] == '-') {
                        num--;
                        mi = min(mi, num);
                        ma = max(ma, num);
                    }
                    ans = max(ans, ma - mi);
                }
            }

            rep(ptr, s.size()+1) {
                int num = 0, mi = 0, ma = 0;
                rep(i, s.size()) {
                    if (i < ptr && s[i] == '-') {
                        num++;
                        mi = min(mi, num);
                        ma = max(ma, num);
                    } else if (i >= ptr && s[i] == '+') {
                        num--;
                        mi = min(mi, num);
                        ma = max(ma, num);
                    }
                    ans = max(ans, ma - mi);
                }
            }

            return ans;
            */
            int p = 0, m = 0;
            rep(i, s.length()) {
                if (s[i] == '+') p++;
                else m++;
            }
            return max(p, m);
        }
};

 
signed main()
{
    MaximumRangeDiv2 cs;
    string st;
    cin >> st;
    cout << cs.findMax(st) << endl;

    return 0;
}

