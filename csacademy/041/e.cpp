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
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder

vi cand, date;
int n, m;

bool solve(int num)
{
    //std::cout << num << std::endl;
    vi table(n+1, 0);
    table[0] = num;
    rep(i, num) {
        if (date[i] > n) {
            return false;
        }
        table[date[i]]--;
    }
    Rep(i, table.size()) {
        table[i] += table[i-1];
    }

    /*
    rep(i, table.size()) {
        std::cout << table[i] << " ";
    }cout << endl;
    */

    vi sum(n, 0);
    rep(i, n) {
        sum[i] = cand[i] - table[i];
 //       cout << sum[i] << " ";
    }
//    cout << endl;

    int ptr = n-1;
    while (ptr > 0 && sum[ptr] >= 0) {
        ptr--;
    }
    if (ptr == 0 && sum[0] >= 0) {
        return true;
    }
    for (int i = n-1; i >= 0; i--) {
        if (sum[i] < 0) {
            return false;
        }
        sum[ptr] += sum[i];
        while (ptr > 0 && sum[ptr] >= 0) {
            ptr--;
        }
    }
    if (sum[0] >= 0) {
        return true;
    } else {
        return false;
    }
}

signed main()
{
    cin >> n >> m;
    cand = vi(n); date = vi(m);
    rep(i, n) cin >> cand[i];
    rep(i, m) cin >> date[i];
    sort(all(cand));
    reverse(all(cand));

    if (!solve(1)) {
        std::cout << 0 << std::endl;
        return 0;
    }
    if (solve(m)) {
        std::cout << m << std::endl;
        return 0;
    }

    int left = 1, right = m;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (solve(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    std::cout << left << std::endl;

    return 0;
}

