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
    priority_queue<int> pq;
    vi a(5);
    rep(i, 5) cin >> a[i];
    rep(i, 5) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                pq.push(a[i]+a[j]+a[k]);
            }
        }
    }
    pq.pop();
    pq.pop();
    cout << pq.top() << endl;

    return 0;
}

