#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
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
// matrix dinic next_combination topcoder
// stack size = 128 * 1024 * 1024


class TheMatrix
{ 
    public:
        int MaxArea(vector <string> ban)
        {
            int h = ban.size(), w = ban[0].size();
            vvi funami(h, vi(w, 1));
            rep(i, h) {
                Rep(j, w) {
                    if (ban[i][j] == ban[i][j-1]) funami[i][j] = 1;
                    else funami[i][j] = funami[i][j-1]+1;
                }
            }
            /*
            rep(i, h) {
                rep(j, w) cout << funami[i][j] << " ";
                cout << endl;
            }
            */
            int ret = 0;
            rep(i, h) {
                rep(j, w) {
                    int len = 1, tmp = funami[i][j];
                    ret = max(ret, len * tmp);
                    for (int k = i+1; k < h; k++) {
                        if (ban[k-1][j] == ban[k][j]) {
                            break;
                        } else {
                            len++;
                            tmp = min(tmp, funami[k][j]);
                            ret = max(ret, len * tmp);
                        }
                    }
                }
            }
            return ret;
        }
};



int main()
{
    Int(n);
    TheMatrix solve;
    vector<string> input(n);
    rep(i, n) {
        cin >> input[i];
    }
    std::cout << solve.MaxArea(input) << std::endl;


    return 0;
}
