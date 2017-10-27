#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-8
#define int long long 
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define pb push_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector< vi >
#define vb vector<bool>
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

int floor(int a, int b)
{
    //return a / b + !!(a % b);
    return a / b;
}

signed main()
{
    int2(n, m);
    //if (!m) { cout << 1 << endl; return 0; }
    if (n == 1) {
        cout << (m + 1LL) % MOD << endl;
        return 0;
    }

    int k = m / (n - 1);

    cout << ( (k*m + k - (n-1)*(k+1)*k)/2 * 2 + m + 1 ) % MOD << endl;

    return 0;
}

