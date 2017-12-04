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
// matrix dinic next_combination

signed main()
{
    int2(n, k);
    int alp = 26;
    vi st(alp, -1), en(alp, -1);

    string data;
    cin >> data;
    rep(i, n) {
        //std::cout << data[i]-'A' << std::endl;
        if (st[data[i]-'A'] == -1) {
            st[data[i]-'A'] = i;
            en[data[i]-'A'] = i;
        } else {
            en[data[i]-'A'] = i;
        }
    }
//    std::cout << "=====" << std::endl;
    vi wa(n+2, 0);
    rep(i, alp) {
        //std::cout << st[i] << " " << en[i]+1 << std::endl;
        if (st[i] != -1) {
            wa[st[i]]++;
            wa[en[i]+1]--;
        }
    }
    Rep(i, n+1) {
        wa[i] += wa[i-1];
    }
    int ret = 0;
    rep(i, n+1) {
        ret = max(ret, wa[i]);
    }
    if (ret <= k) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }


    return 0;
}



