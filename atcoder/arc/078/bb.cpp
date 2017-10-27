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
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
vi black, white;
int n;
vvi graph;
 
void dfsw(int pos, int dep)
{
    if (white[pos] != -1) return ;
    white[pos] = dep;
    rep(i, graph[pos].size()) {
        dfsw(graph[pos][i], dep+1);
    }
}
 
void dfsb(int pos, int dep)
{
    if (black[pos] != -1) return ;
    black[pos] = dep;
    rep(i, graph[pos].size()) {
        dfsb(graph[pos][i], dep+1);
    }
}
 
 
signed main()
{
    cin >> n;
    graph = vvi(n);
    black = vi(n, -1);
    white = vi(n, -1);
    rep(i, n-1) {
        int2(a, b);
        graph[a-1].pb(b-1);
        graph[b-1].pb(a-1);
    }
 
    dfsw(n-1, 0);
    dfsb(0, 0);
/*
    rep(i, n) {
        cout << white[i] << " ";
    }cout << endl;
    rep(i, n) {
        cout << black[i] << " ";
    }cout << endl;
*/
    int cnt = 0;
    rep(i, n) {
        cnt += (white[i] < black[i]) ? 1 : -1;
    }
    if (cnt < 0) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
 
    return 0;
}
