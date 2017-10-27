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
 
int upcal(int a, int b)
{
    if (a <= 0) {
        return 0;
    } else {
        int ret = a / b;
        if (a % b) ret++;
        return ret;
    }
}

signed main()
{
    Int(n);
    int2(a, b);
    vi data(n);

    rep(i, n) {
        cin >> data[i];
    }

    int l = 0, r = 1000000000;
    while ( r - l > 1 ) {
        int mid = (l + r) / 2;
        int sum = 0;
        //cout << mid << " ";
        rep(i, n) {
            //cout << upcal(data[i] - mid * b, a) << " ";
            sum += upcal(data[i] - mid * b, a - b);
        }
        //cout << sum << endl;
        if (sum <= mid) {
            //cout << "true" << endl;
            r = mid;
        } else {
            //cout << "false" << endl;
            l = mid;
        }
    }

    cout << r << endl;

    return 0;
}

