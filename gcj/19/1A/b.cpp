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

void solve()
{
    int2(a, b);
if (a == 2 && b == 2) {
cout << "IMPOSSIBLE" << endl;
}
if (a == 2 && b == 3) {
cout << "IMPOSSIBLE" << endl;
}
if (a == 2 && b == 4) {
cout << "IMPOSSIBLE" << endl;
}
if (a == 2 && b == 5) {
cout << "POSSIBLE" << endl;
cout << "1 1" << endl;
cout << "2 4" << endl;
cout << "1 2" << endl;
cout << "2 5" << endl;
cout << "1 3" << endl;
cout << "2 1" << endl;
cout << "1 4" << endl;
cout << "2 2" << endl;
cout << "1 5" << endl;
cout << "2 3" << endl;
}
if (a == 3 && b == 2) {
cout << "IMPOSSIBLE" << endl;
}
if (a == 3 && b == 3) {
cout << "IMPOSSIBLE" << endl;
}
if (a == 3 && b == 4) {
cout << "POSSIBLE" << endl;
cout << "3 2" << endl;
cout << "2 4" << endl;
cout << "1 1" << endl;
cout << "2 3" << endl;
cout << "3 1" << endl;
cout << "1 2" << endl;
cout << "3 3" << endl;
cout << "2 1" << endl;
cout << "1 4" << endl;
cout << "2 2" << endl;
cout << "3 4" << endl;
cout << "1 3" << endl;
}
if (a == 3 && b == 5) {
cout << "POSSIBLE" << endl;
cout << "1 1" << endl;
cout << "2 4" << endl;
cout << "3 2" << endl;
cout << "1 5" << endl;
cout << "2 3" << endl;
cout << "3 1" << endl;
cout << "1 4" << endl;
cout << "2 2" << endl;
cout << "3 5" << endl;
cout << "2 1" << endl;
cout << "3 4" << endl;
cout << "1 3" << endl;
cout << "2 5" << endl;
cout << "3 3" << endl;
cout << "1 2" << endl;
}
if (a == 4 && b == 2) {
cout << "IMPOSSIBLE" << endl;
}
if (a == 4 && b == 3) {
cout << "POSSIBLE" << endl;
cout << "1 1" << endl;
cout << "3 2" << endl;
cout << "1 3" << endl;
cout << "2 1" << endl;
cout << "4 2" << endl;
cout << "2 3" << endl;
cout << "3 1" << endl;
cout << "1 2" << endl;
cout << "3 3" << endl;
cout << "4 1" << endl;
cout << "2 2" << endl;
cout << "4 3" << endl;
}
if (a == 4 && b == 4) {
cout << "POSSIBLE" << endl;
cout << "1 1" << endl;
cout << "2 3" << endl;
cout << "3 1" << endl;
cout << "4 3" << endl;
cout << "2 2" << endl;
cout << "3 4" << endl;
cout << "4 2" << endl;
cout << "1 4" << endl;
cout << "3 3" << endl;
cout << "4 1" << endl;
cout << "1 3" << endl;
cout << "2 1" << endl;
cout << "4 4" << endl;
cout << "1 2" << endl;
cout << "2 4" << endl;
cout << "3 2" << endl;
}
if (a == 4 && b == 5) {
cout << "POSSIBLE" << endl;
cout << "4 2" << endl;
cout << "2 1" << endl;
cout << "3 4" << endl;
cout << "1 3" << endl;
cout << "3 2" << endl;
cout << "4 5" << endl;
cout << "2 4" << endl;
cout << "4 3" << endl;
cout << "1 1" << endl;
cout << "3 5" << endl;
cout << "1 4" << endl;
cout << "2 2" << endl;
cout << "4 1" << endl;
cout << "2 5" << endl;
cout << "3 3" << endl;
cout << "1 2" << endl;
cout << "3 1" << endl;
cout << "4 4" << endl;
cout << "2 3" << endl;
cout << "1 5" << endl;
}
if (a == 5 && b == 2) {
cout << "POSSIBLE" << endl;
cout << "1 1" << endl;
cout << "3 2" << endl;
cout << "5 1" << endl;
cout << "2 2" << endl;
cout << "4 1" << endl;
cout << "1 2" << endl;
cout << "3 1" << endl;
cout << "5 2" << endl;
cout << "2 1" << endl;
cout << "4 2" << endl;
}
if (a == 5 && b == 3) {
cout << "POSSIBLE" << endl;
cout << "2 3" << endl;
cout << "3 1" << endl;
cout << "5 2" << endl;
cout << "1 3" << endl;
cout << "2 1" << endl;
cout << "4 2" << endl;
cout << "1 1" << endl;
cout << "3 2" << endl;
cout << "5 1" << endl;
cout << "1 2" << endl;
cout << "3 3" << endl;
cout << "4 1" << endl;
cout << "5 3" << endl;
cout << "2 2" << endl;
cout << "4 3" << endl;
}
if (a == 5 && b == 4) {
cout << "POSSIBLE" << endl;
cout << "1 1" << endl;
cout << "2 3" << endl;
cout << "3 1" << endl;
cout << "4 3" << endl;
cout << "5 1" << endl;
cout << "1 3" << endl;
cout << "2 1" << endl;
cout << "3 3" << endl;
cout << "4 1" << endl;
cout << "5 3" << endl;
cout << "2 2" << endl;
cout << "3 4" << endl;
cout << "4 2" << endl;
cout << "5 4" << endl;
cout << "1 2" << endl;
cout << "2 4" << endl;
cout << "3 2" << endl;
cout << "4 4" << endl;
cout << "5 2" << endl;
cout << "1 4" << endl;
}
if (a == 5 && b == 5) {
cout << "POSSIBLE" << endl;
cout << "1 1" << endl;
cout << "2 4" << endl;
cout << "3 2" << endl;
cout << "4 5" << endl;
cout << "5 3" << endl;
cout << "2 2" << endl;
cout << "3 5" << endl;
cout << "4 3" << endl;
cout << "5 1" << endl;
cout << "1 4" << endl;
cout << "3 3" << endl;
cout << "4 1" << endl;
cout << "5 4" << endl;
cout << "1 2" << endl;
cout << "2 5" << endl;
cout << "4 4" << endl;
cout << "5 2" << endl;
cout << "1 5" << endl;
cout << "2 3" << endl;
cout << "3 1" << endl;
cout << "5 5" << endl;
cout << "1 3" << endl;
cout << "2 1" << endl;
cout << "3 4" << endl;
cout << "4 2" << endl;
}
    
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(t);
    rep(i, t) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
