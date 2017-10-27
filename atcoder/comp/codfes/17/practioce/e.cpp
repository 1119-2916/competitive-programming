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
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vector<int> data(m);
    for (int i = 0; i < m; i++) {
        cin >> data[i];
    }
    sort(all(data));

    if (n == m) {
        cout << 0 << endl;
        return 0;
    }

    int l = 0, r = n*2+2;
    while (l + 1 < r) {
        int mid = (l + r) / 2LL;
        int left = 0;

        rep(j, m) {
            if (left + 1 == data[j]) left++;
            if (left < data[j]) {
                int dist = data[j] - (left+1);
                if (mid < dist) {
                    break;
                } else if (mid <= dist * 2) {
                    left = data[j];
                } else {
                    left = data[j] + mid - dist * 2;
                }
            } else {
                left = max(left, data[j]+mid);
            }
        }
        if (left >= n) {
            r = mid;
            continue;
        }
        int right = n+1;
        for (int j = m-1; j >= 0; j--) {
            if (right - 1 == data[j]) right--;
            if (right > data[j]) {
                int dist = right - data[j] - 1;
                if (mid < dist) {
                    break;
                } else if (mid <= dist * 2) {
                    right = data[j];
                } else {
                    right = data[j] - (mid - dist * 2);
                }
            } else {
                right = min(right, data[j]-mid);
            }
        }
        if (right <= 1) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;


    return 0;
}



