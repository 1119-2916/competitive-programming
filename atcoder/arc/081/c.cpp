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

    string data;
    cin >> data;
    int n = data.size();
    std::cout << "size : " << data.size() << std::endl;
    vi cnt(26, 0), div;

    //for (int i = data.size()-1; i >= 0; i--) {
    rep(i, data.size()) {
        cnt[data[i]-'a']++;
        bool yui = true;
        rep(j, 26) {
            if (!(cnt[j])) {
                yui = false;
            }
        }
        if (yui) {
            div.pb(i);
            std::cout << "div : " << i << " " << data[i] << std::endl;
            rep(j, cnt.size()) {
                std::cout << cnt[j] << " ";
                cnt[j] = 0;
            }
            cout << endl;
        }
    }

    string ans;
    rep(i, div.size()-1) {
        ans.pb('a');
    }

    vi nct(26, 0);
    vector<char> kyoko(n, 0);
    for (int i = data.size()-1; i >= 0; i--) {
        nct[data[i]-'a']++;
        bool yui = true;
        rep(j, 26) {
            if (!(nct[j])) {
                if (!kyoko[data[i]-'a']) {
                    kyoko[data[i]-'a'] = j + 'a';
                }
                yui = false;
            }
        }
        if (yui) break;
    }

    rep(i, 26) {
        if (!cnt[kyoko[i] - 'a']) {
            ans.pb(i + 'a');
            ans.pb(kyoko[i]);
            break;
        }
    }

    std::cout << ans << std::endl;

    /*
    int ans = 0;
    rep(i, 26) {
        if (cnt[ans] > cnt[i]) {
            ans = i;
        }
    }
    std::cout << ans << std::endl;
    string ret;
    if (cnt[ans]) {
        rep(i, cnt[ans]+1) {
            ret.pb('a' + ans);
        }
    } else {
        ret.pb('a' + ans);
    }
    std::cout << ret << std::endl;
    */


    return 0;
}


