#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define pb push_back
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
 
class TreeMovingDiv2 {
    public:
        int count(int n, vector <int> roots, vector <int> a,
                vector <int> b, vector <int> c) {
            vi x(a.size());
            vector < vvi > t(a.size(), vvi(n, vi()));

            rep(i, a.size()) {
                cout << "==" << i << "==" << endl;
                x[0] = c[i];
                Rep(j, n-1) {
                    x[j] = ((a[i] * x[j-1]) + b[i]) % MOD;
                }
                rep(j, n-1) {
                    long a = (roots[i] + j + 1) % n;
                    long b = (roots[i] + (x[j] % (j+1))) % n;
                    t[i][a].pb(b);
                    t[i][b].pb(a);
                    cout << a << " " << b << endl;
                }
            }
            return 0;
        }
};


