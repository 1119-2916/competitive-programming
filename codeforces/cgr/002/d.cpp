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
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

int solve(vi &data, int p)
{
    if (data[0] >= p) return -1;
    if (data.back() < p) return data.size()-1;

    int l = 0, r = data.size()-1; // x, o
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (data[mid] < p) l = mid;
        else r = mid;
    }
    return l;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(all(data));
    auto result = unique(all(data));
    data.erase(result, data.end());

    vi dist(data.size(), 0);
    Rep(i, data.size()) {
        dist[i-1] = data[i] - data[i-1];
    }
    dist[dist.size()-1] = INF;

    sort(all(dist));

    vi funami(dist.size(), 0);
    funami[0] = dist[0];
    Rep(i, funami.size()) {
        funami[i] = funami[i-1] + dist[i];
    }
    /*
    rep(i, funami.size()) {
        cout << funami[i] << " ";
    }cout << endl;
    */
    Int(q);
    while (q--) {
        int2(a, b);
        int k = b - a + 1;
        int p = solve(dist, k);
        //std::cout << p << std::endl;
        if (p == -1) {
            cout << dist.size() * k << " ";
        } else {
            cout << funami[p] + (dist.size() - p - 1) * k << " ";
        }
        //cout << endl;
    }
    cout << endl;

    return 0;
}
