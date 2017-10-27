#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define ll long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
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
#define Int(x) int x; scanf("%d", &x);
#define int2(x, y) int x, y; scanf("%d %d", &x, &y);
#define int3(x, y, z) int2(x, y) Int(z)
#define fir first
#define sec second
#define ffir fir.fir
#define fsec fir.sec
#define sfir sec.fir
#define ssec sec.sec
#define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));

#define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm
// stack size = 128 * 1024 * 1024

vvi graph, edge;

class Egalitarianism3
{ 
    public:
        void dfs(int par, int pos, int score, vi &cnt)
        {
            //std::cout << pos << " " ;
            cnt.pb(score);
            rep(i, edge.size()) {
                if (edge[pos][i] && i != par) {
                    dfs(pos, i, score + graph[pos][i], cnt);
                }
            }
        }

        int maxCities(int n, vi a, vi b, vi len)
        {
            std::cout << n << std::endl;
            graph = vvi(n, vi(n, INF));
            rep(i, n) graph[i][i] = 0;
            edge = vvi(n, vi(n, 0));
            rep(i, a.size()) {
                graph[a[i]-1][b[i]-1] = len[i];
                graph[b[i]-1][a[i]-1] = len[i];
                edge[a[i]-1][b[i]-1] = 1;
                edge[b[i]-1][a[i]-1] = 1;
            }
            rep(k, n) rep(i, n) rep(j, n) 
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            /*
            rep(i, n) {
                rep(j, n) {
                    std::cout << edge[i][j] << " ";
                }
                cout << endl;
            }
            */
            int ret = min(2, n);
            rep(i, n) {
                //std::cout << i << " : " << std::endl;
                map<int, int> mp;
                rep(j, n) {
                    if (edge[i][j]) {
                        //std::cout << j << " " << edge[i][j] << endl;
                        vi cnt;
                        dfs(i, j, graph[i][j], cnt);
                        sort(all(cnt));
                        //rep(k, cnt.size()) cout << cnt[k] << " ";
                        //cout << endl;
                        cnt.erase(unique(all(cnt)), cnt.end());
                        rep(k, cnt.size()) {
                            //std::cout << cnt[k] << " ";
                            mp[cnt[k]]++;
                        }
                        //cout << endl;
                        //rep(k, cnt.size()) cout << cnt[k] << " ";
                        //cout << endl;
                    }
                }
                int tmp = 0;
                for (auto j = mp.begin(); j != mp.end(); j++) {
                    tmp = max(tmp, j->second);
                }
                //std::cout << tmp << std::endl;
                ret = max(ret, tmp);
            }
            return ret;
        }
};



int main()
{
    Int(n);
    n--;
    vi a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    Egalitarianism3 solve;
    std::cout << solve.maxCities(n+1, a, b, c) << std::endl;

    return 0;
}
