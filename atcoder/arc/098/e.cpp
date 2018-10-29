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
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(n, k, q);
    vector<int> data(n);
    vp table(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        table[i].fir = data[i];
        table[i].sec = i;
    }
    sort(all(table));
    
    vi state(n, 0);

    int ret = INF;
    rep(i, n) {
        cout << "call : " << i << endl;
        vi funami, yui;
        rep(j, n) {
            if (state[j]) {
                sort(all(yui));
                reverse(all(yui));
                cout << " add {";
                for (int ptr = k-1; ptr < yui.size(); ptr++) {
                    cout << yui[ptr] << ", ";
                    funami.pb(yui[ptr]);
                }
                cout << "}" << endl;
                yui.assign(0, 0);
            } else {
                yui.pb(data[j]);
            }
            rep(ptr, yui.size()) cout << yui[ptr] << " "; cout << endl;
        }

        sort(all(yui));
        reverse(all(yui));
        cout << " add {";
        for (int ptr = k-1; ptr < yui.size(); ptr++) {
            cout << yui[ptr] << ", ";
            funami.pb(yui[ptr]);
        }
        cout << "}" << endl;

        sort(all(funami));
        cout << "funami : ";
        rep(ptr, funami.size()) cout << funami[ptr] << " "; cout << endl;

        int ans = INF;
        for (int j = 0; j + q - 1 < funami.size(); j++) {
            cout << "get : " << j << " "  << j + q - 1 << endl;
            ans = min(ans, funami[j + q - 1] - funami[j]);
            cout << "ans : " << ans << endl;
        }
        ret = min(ret, ans);
        state[table[i].sec] = 1;
    }
    assert(ret != INF);
    cout << ret << endl;

    return 0;
}
