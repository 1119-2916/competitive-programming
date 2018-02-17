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
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

void make(vp &data, vi &price, vi &value, int num)
{ 
    int targ = (1 << price.size());
    //cout << "targ : " << targ << endl;
    Rep(i, targ) {
        int yui = 0, kyoko = 0, akari = 0;
        for (int j = 0; j < price.size(); j++) {
            if (i & (1 << j)) {
                yui += (1 << j);
                kyoko += price[j];
                akari += value[j];
            }
        }
        //cout << yui << " " << kyoko << " " << akari << endl;
        if (kyoko <= num) {
            data.pb({akari, yui});
        }
    }
}

bool next_combination(std::vector<int>& v, int n) {
    int k = v.size();
    int p = k - 1;
    if (v[p] >= n) return false;
    while (p >= 0 && ++v[p] >= n - (k - p - 1)) --p;
    if (p < 0) return false;
    ++p;
    while (p < k) {
        v[p] = v[p - 1] + 1;
        ++p;
    }
    return true;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> item(n);
    for (int i = 0; i < n; i++) {
        cin >> item[i];
    }
    vector<int> price(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    vector<int> value(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    int out = 0;

    Rep(i, n) {
        int money = 0;
        rep(j, i) {
            money += item[j];
        }
        cout << "money : " << money << endl;
        vp data(0);
        make(data, price, value, money);
        sort(all(data));
        reverse(all(data));
        rep(j, data.size()) 
            cout << data[j].fir << " " << data[j].sec << endl;

        int 
        rep(j, data.size()) {

        
        out = max(out, ans);
        //cout << endl;
    }
    std::cout << out << std::endl;

    return 0;
}




