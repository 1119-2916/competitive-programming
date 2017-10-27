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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign


int length, n;
int l[102], r[102];

signed main()
{
    while (cin >> n >> length, (n|length)) {
        memset(r, 0, sizeof(r));
        memset(l, 0, sizeof(l));
        rep(i, n) {
            char tmpc;
            int tmp;
            cin >> tmpc >> tmp;
            if (tmpc == 'L') {
                l[tmp] = i+1;
            } else {
                r[tmp] = i+1;
            }
        }
            //rep(i, length+1) { cout << l[i] << " "; } cout << endl;
            //rep(i, length+1) { cout << r[i] << " "; } cout << endl;
        int fl = n;
        int ans_num = 0, ans_time = 0;
        while (fl) {
            rep(i, length) {
                if (l[i]) {
                    l[i-1] = l[i];
                    l[i] = 0;
                }
            }
            for (int i = length-1; i >= 0; i--) {
                if (r[i]) {
                    r[i+1] = r[i];
                    r[i] = 0;
                }
            }
            //rep(i, length+1) { cout << l[i] << " "; } cout << endl;
            //rep(i, length+1) { cout << r[i] << " "; } cout << endl;
            rep(i, length+1) {
                if (r[i] && l[i]) {
                    int tmp = r[i];
                    r[i] = l[i];
                    l[i] = tmp;
                }
            }
            if (r[length]) {
                fl--;
                ans_num = r[length];
                r[length] = 0;
            }
            if (l[0]) {
                fl--;
                ans_num = l[0];
                l[0] = 0;
            } 
            ans_time++;
        }
        cout << ans_time << " " << ans_num << endl;
    }

    return 0;
}

