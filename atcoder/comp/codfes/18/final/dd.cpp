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

/*
 * 空間 O(alphabet_num) なので注意　座圧した奴も作りたい
 */
template< size_t alphabet_num >
struct char_backet
{
    vector<vector<int>> backet;
    string data;
    char_backet();
    char_backet(string data) : data(data) {
        backet.assign(alphabet_num, vector<int>(0, 0));
        for (int i = 0; i < data.size(); i++) {
            backet[data[i]].pb(i);
        }
        for (int i = 0; i < backet.size(); i++) backet[i].pb(INF);
    }
    bool substr(string targ) {
        int ptr = -1;
        for (int i = 0; i < targ.size(); i++) {
            ptr = *upper_bound(all(backet[targ[i]]), ptr);
            if (ptr == INF) break;
        }
        return ptr != INF;
    }
};

/*
pii solve(vector<string> &data, char a, char b)
{
    vector<int> cnt('z'+1, 0);
    rep(i, data.size()) {
        int fl = 0;
        vi tmp('z'+1, 0);
        rep(j, data[i].size()) {
            if (!fl && (char)data[i][j] == a) fl++;
            else if (fl == 1 && (char)data[i][j] == b) fl++;
            else if (fl == 2) tmp[(char)data[i][j]] = 1;
        }
        rep(j, cnt.size()) {
            cnt[j] += tmp[j];
        }
    }
    int ptr = 0;
    rep(i, cnt.size()) {
        if (cnt[ptr] < cnt[i]) ptr = i;
    }
    if (!cnt[ptr]) return {0, -1};
    else return {a * 1000000 + b * 1000 + ptr, cnt[ptr]};
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<string> data(n);
    rep(i, n) cin >> data[i];

    int ans = 0, ans_cnt = 0;
    for (char i = 'A'; i <= 'z'; i++) {
        for (char j = 'A'; j <= 'z'; j++) {
            pii tmp = solve(data, i, j);
            if (tmp.sec > ans_cnt) {
                ans_cnt = tmp.sec;
                ans = tmp.fir;
            }
            if (j == 'Z') j = 'a' - 1;
        }
        if (i == 'Z') i = 'a' - 1;
    }
    cout << (char)(ans / 1000000) << (char)((ans / 1000) % 1000) << (char)(ans % 1000) << endl;

    return 0;
}

*/


signed main()
{

    string st;
    cin >> st;
    char_backet<'z'> cb(st);

    cin >> st;
    cout << cb.substr(st) << endl;



    return 0;
}

