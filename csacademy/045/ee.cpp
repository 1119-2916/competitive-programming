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

bool check(string st)
{
    for (int i = 0; i < st.size()/2; i++) {
        if (st[i] != st[st.size()-i-1]) {
            return false;
        }
    }
    return true;
}

string make(int a, int b)
{
    string ret;
    rep(i, a) {
        if (b % 2) {
            ret.pb('1');
        } else {
            ret.pb('0');
        }
        b /= 2;
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);


    for (int l = 1; l < 10; l++) {
        for (int k = 0; k < (1 << l); k++) {
            string st;
            //cin >> st;
            st = make(l, k);

            set<string> yui;
            Rep(i, st.size()+1) {
                for (int j = 0; j + i < st.size() + 1; j++) {
                    if (check(st.substr(j, i))) { 
                        if (yui.find(st.substr(j, i)) == yui.end()) {
                            //std::cout << st.substr(j, i) << std::endl;
                            yui.insert(st.substr(j, i));
                        }
                    }
                }
            }

            if (yui.size() != l) {
                std::cout << l << std::endl;
                std::cout << st << std::endl;
                return 0;
            }
        }
    }
    //std::cout << yui.size() << std::endl;

    return 0;
}
