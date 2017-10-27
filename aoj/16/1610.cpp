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
    Int(a);
    Int(b);
    while (a && b) {
        vb bloss(7368799, false);
        for (int i = a, cnt = 0; cnt < b; i++) {
            if (!bloss[i]) {
                for (int j = 1; j * i < 7368799; j++) {
                    bloss[i*j] = true;
                }
                cnt++;
            }
        }
        for (int i = a; i < bloss.size(); i++) {
            if (!bloss[i]) {
                cout << i << endl;
                break;
            }
        }
        cin >> a >> b;
    }
    return 0;
}

