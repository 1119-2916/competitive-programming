#include <bits/stdc++.h>
 
using namespace std;
 
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
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%d", &x);
#define int2(x, y) int x, y; scanf("%d %d", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

class CoinConstruction {

public :
    vector <int> construct(int k) {
        vi ans;
        if (k == 1) { ans.pb(114514); return ans; }
        int ret = 0;
        while (pow(2, ret) < k) {
            cout << pow(2, ret) << endl;
            ret++;
        }
        rep(i, ret-1) {
            ans.pb(1<<i);
        }
        ans.pb(pow(2, ret-1) - (pow(2, ret) - k - 1));
        for (int i : ans) cout << i << endl;
        return ans;
    }
};



int main()
{
    Int(n);
    CoinConstruction c;
    c.construct(n);

    return 0;
}

