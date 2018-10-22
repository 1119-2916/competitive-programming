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
 
signed main()
{

    int2(H, W);
    int2(h, w);

    vvi funami(H, vi(W, 1));
    Rep(i, H+1) {
        Rep(j, W+1) {
            if (i % h == 0 && j % w == 0) {
                funami[i-1][j-1] = -(h*w+1);
            } else if (i % h == 1 && j % w == 1) {
                funami[i-1][j-1]++;
            }
        }
    }

    int sum = 0;
    rep(i, funami.size()) {
        rep(j, funami[i].size()) {
            sum += funami[i][j];
        }
    }

    if (sum <= 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        rep(i, funami.size()) {
            rep(j, funami[i].size()) {
                std::cout << funami[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

