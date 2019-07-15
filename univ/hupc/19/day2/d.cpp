#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
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

using Weight = int;
using Flow = int;
struct Edge {
    int s, d; Weight w; Flow c;
    Edge() {};
    Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1) {
    g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
    addArc(g, a, b, w);
    addArc(g, b, a, w);
}

int solve(Graph &g, vi &used, int pos, int hop)
{
    if (used[pos]) return hop;
    used[pos] = 1;
    return solve(g, used, g[pos][0].d, hop+1);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, r);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        data[i]--;
    }

    Graph g(n);
    rep(i, data.size()) {
        addArc(g, i, data[i]);
    }

    vi used(n, 0);
    map<int, int> poka;
    rep(i, n) {
        if (!used[i]) {
            poka[solve(g, used, i, 0)]++;
        }
    }

    vi dp(n+1, 0);
    dp[0] = 1;
    for (auto i = poka.begin(); i != poka.end(); i++) {
        int tmp = i->sec;
        for (int k = 1; tmp > 0; k*=2) {
            int key = min(tmp, k);
            tmp -= key;
            for (int j = dp.size()-1; j >= 0; j--) {
                if (j + key * i->fir < dp.size() && dp[j]) 
                    dp[j + key * i->fir] = 1;
            }
        }
    }

    if (dp[r] || dp[n-r]) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }


    return 0;
}
