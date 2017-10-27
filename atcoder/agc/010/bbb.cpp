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
    Int(n);
    int sum = 0;
    vi data(n, 0);
    rep(i, n) {
        cin >> data[i];
        sum += data[i];
    }

    int k = sum / (n * (n + 1) / 2);
    if (k * (n * (n + 1) / 2) != sum) {
        cout << "NO" << endl;
        return 0;
    }

    vi dist(n, 0);

    rep(i, n-1) {
        dist[i] = data[i+1] - data[i] - k;
    }
    dist[n-1] = data[0] - data[n-1] - k;

    rep(i, n) {
        if (dist[i] > 0 or (-dist[i]) % n) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
