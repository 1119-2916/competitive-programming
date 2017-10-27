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


long long n, m, a[300009], c, p[300009];
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n - 1; i++) { c += (a[i + 1] - a[i] + m) % m; }
	for (int i = 1; i <= n - 1; i++) {
		long long L = a[i] + 2, R = a[i + 1] + 1;
		if (L > R)R += m;
		if ((a[i + 1] - a[i] + m) % m < 2)continue;
		p[L]++; p[R] -= (R - L + 1); p[R + 1] += (R - L);
	}
	for (int i = 1; i <= 300000; i++)p[i] += p[i - 1];
	for (int i = 1; i <= 300000; i++)p[i] += p[i - 1];
    rep(i, m+2) {
        cout << p[i] << " ";
    }
    cout << endl;
	long long maxn = 0;
	for (int i = 1; i <= m; i++)maxn = max(maxn, p[i] + p[i + m] + p[i + m + m]);
	cout << c - maxn << endl;
	return 0;
}

/*
vi data;
int n, m;

signed main()
{
    cin >> n >> m;
    data = vi(n);
    rep(i, n) cin >> data[i];

    vi state(m+2, 0);
    rep(i, n-1) {
        if (data[i] < data[i+1]) {
            //if (data[i+1] - data[i] < 2) continue;
            state[data[i]+1]++;
            state[data[i+1]+1]--;
        } else {
            state[0]++;
            state[data[i+1]+1]--;
            state[data[i]+1]++;
        }
    }
    rep(i, m+2) {
        cout << state[i] << " ";
    }
    cout << endl;
    Rep(i, m+2) {
        state[i] += state[i-1];
    }
    rep(i, m+2) {
        cout << state[i] << " ";
    }
    cout << endl;

    vi num(m+1, 0);
    Rep(i, n) {
        num[data[i]]++;
    }
    rep(i, num.size()) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
*/
