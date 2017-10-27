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
 
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a%b); }

signed main()
{
    int2(a, b);
    int tmp = gcd(a, b);
    if (a / tmp == 4 && b / tmp == 3 || 
            a / tmp == 3 && b / tmp == 4) {
        cout << "4:3" << endl;
    } else {
        cout << "16:9" << endl;
    }

    return 0;
}

