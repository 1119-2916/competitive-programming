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

signed main()
{
    string data;
    cin >> data;
    int n = data.size();

    int zero = 0;
    rep(i, n) {
        if (data[i] == '0') {
            zero++;
        }
    }

    int ptr = 0;
    while (ptr < n && data[ptr] == '1') {
        ptr++;
    }
    int cnt = 0;
    while (ptr < n && data[ptr] == '0') {
        cnt++;
        ptr++;
    }
    ptr++;
    while (ptr < n && data[ptr] == '0') {
        cnt++;
        ptr++;
    }
    if (cnt == zero) {
        std::cout << zero << std::endl;
        return 0;
    }

    vi state;
    int now = data[0];
    cnt = 1;
    Rep(i, n) {
        if (data[i] == now) {
            cnt++;
        } else {
            state.pb( cnt * ( (now == '0') ? 1 : -1) );
            cnt = 1;
            now = data[i];
        }
    }
    state.pb( cnt * (now == '0' ? 1 : -1) );
    /*
    rep(i, state.size()) {
        std::cout << state[i] << std::endl;
    }*/

    int ans = 0;
    rep(i, state.size()) {
        if (state[i] > 0) {
            ans = max(ans, state[i]+1);
            if (i + 2 < state.size() && 
                    state[i+1] == -1 ) {
                ans = max(ans, state[i] + state[i+2] + 1);
            }
        }
      //  std::cout << ans << std::endl;
    }
    std::cout << ans << std::endl;




    return 0;
}





