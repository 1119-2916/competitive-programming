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
 
signed main()
{
    int n;
    while (cin >> n, n) {
        vector<string> data(n);
        rep(i, n) {
            cin >> data[i];
            rep(j, data[i].size()) {
                if (!i) { break; }
                if (data[i][j] != '.') {
                    data[i][j-1] = '+';
                    break;
                }
            }
        }
        for (int i = n-1; i >= 0; i--) {
            rep(j, data[i].size()) {
                if (data[i][j] == '+') {
                    int pt = i-1;
                    while (pt >= 0 && data[pt][j] == '.') {
                        data[pt--][j] = '|';
                    }
                    break;
                }
            }
        }
        rep(i, n) {
            rep(j, data[i].size()) {
                if (data[i][j] == '.') {
                    data[i][j] = ' ';
                }
            }
            cout << data[i] << endl;
        }
    }

    return 0;
}

