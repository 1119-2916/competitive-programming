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


class UniformBoard
{ 
    public:
        int getBoard(vector<string> board, int k)
        {
            int n = board.size();
            int apple = 0;
            bool emp = false;
            rep(i, n) {
                rep(j, n) {
                    apple += (board[i][j] == 'A') ? 1 : 0;
                    emp |= board[i][j] == '.';
                }
            }
            int ans = 0;
            for (int stx = 0; stx < n; stx++) {
                for (int sty = 0; sty < n; sty++) {
                    for (int szx = 1; szx + stx <= n; szx++) {
                        for (int szy = 1; szy + sty <= n; szy++) {
                            int a = 0, p = 0, e = 0;
                            for (int i = stx; i - stx < szx; i++) {
                                for (int j = sty; j - sty < szy; j++) {
                                    if (board[i][j] == 'P') {
                                        p++;
                                    } else if (board[i][j] == 'A') {
                                        a++;
                                    } else if (board[i][j] == '.') {
                                        e++;
                                    }
                                }
                            }
                            if (!emp) {
                                if (!p && !e) {
                                    ans = max(ans, a);
                                }
                            } else {
                                if (apple >= szx * szy &&
                                        k >= e + p + p) {
                                    ans = max(ans, szx * szy);
                                }
                            }
                        }
                    }
                }
            }
            return ans;
        }
};



int main()
{
    int2(n, k);
    vector<string> ban(n);
    rep(i, n) {
        cin >> ban[i];
    }
    UniformBoard solve;
    std::cout << solve.getBoard(ban, k) << std::endl;

    return 0;
}
