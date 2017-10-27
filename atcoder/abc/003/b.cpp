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
 
signed main()
{
    string a, b;
    cin >> a >> b;
    rep(i, a.length()) {
        if (a[i] == b[i]) {
            continue;
        } else if (a[i] == '@' && 
                 (b[i] == 'a' || 
                    b[i] == 't' ||
                    b[i] == 'c' ||
                    b[i] == 'o' ||
                    b[i] == 'd' ||
                    b[i] == 'e' ||
                    b[i] == 'r' ) ) {
                continue;
        } else if (b[i] == '@' && 
                 (a[i] == 'a' || 
                    a[i] == 't' ||
                    a[i] == 'c' ||
                    a[i] == 'o' ||
                    a[i] == 'd' ||
                    a[i] == 'e' ||
                    a[i] == 'r' ) ) {
                continue;
        } else {
            cout << "You will lose" << endl;
            return 0;
        } 
    }
    cout << "You can win" << endl;
        


    return 0;
}

