#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-10
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


int main() {
            int in[4];
            rep(i, 4) cin >> in[i];

            int ans = INF;
            rep(i, 1000001) {
                int tmp = 0;
                rep(j, 4) {
                    tmp += abs(in[j] - i);
                }
                ans = min(ans, tmp);
            }
            cout << ans << endl;


            return 0;
        }

