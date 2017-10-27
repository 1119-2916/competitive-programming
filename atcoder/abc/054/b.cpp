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
 
vector<string> p1, p2;
int n, m;

bool comp1(int add_i, int add_j);
bool comp2(int add_i, int add_j);

signed main()
{
    cin >> n >> m;
    p1.assign(n, "");
    p2.assign(m, "");

    rep(i, n) {
        cin >> p1[i];
    }

    rep(i, m) {
        cin >> p2[i];
    }

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            if (comp1(i, j)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}

bool comp1(int add_i, int add_j)
{
    bool fl = false;
    rep(i, m) {
        rep(j, m) {
            fl = true;
            if (p1[i+add_i][j+add_j] != p2[i][j]) {
                return false;
            }
        }
    }
    return fl;
}

