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

int pay(int num)
{
    int ret = 0;
    while (num) {
        ret += num % 5;
        num -= (num % 5);
        ret += (int)(num % 10 == 5);
        num /= 10;
    }
    return ret;
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, k);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    vector<map<int, int>> ecasdqina(k+1);
    ecasdqina[0][0] = 1;

    rep(i, n) {
        for (int j = k-1; j >= 0; j--) {
            for (auto l : ecasdqina[j]) {
                ecasdqina[j+1][l.fir + data[i]] += l.sec;
            }
        }
    }

    int ans = INF;
    //rep(i, ecasdqina.size()) {
        for (auto j : ecasdqina[k]) {
            ans = min(ans, pay(j.fir));
        }
    //}

    std::cout << ans << std::endl;

    return 0;
}
