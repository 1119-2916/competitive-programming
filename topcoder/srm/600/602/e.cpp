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


class TypoCoderDiv1
{
    public:
    int getmax(vector <int> D, int X)
    {
        int n = D.size();
        int dp[n+1][2200];
        memset(dp, -1, sizeof(dp));
        dp[0][X] = 0;
        int ans = 0;

        rep(i, n) {
            rep(j, 2200) {
                if (dp[i][j] != -1) {
                    //std::cout << i << " " << j << std::endl;
                    dp[i+1][max(0, j-D[i])] = 
                        max(dp[i+1][max(0, j-D[i])], dp[i][j]);
                    if (j + D[i] < 2200) {
                        dp[i+1][j+D[i]] = max(dp[i+1][j+D[i]], dp[i][j]);
                    } else if (i+1 != n) {
                        if (j + D[i] - D[i+1] < 2200) {
                            dp[i+2][max(0, j+D[i]-D[i+1])] = 
                                max(dp[i+2][max(0, j+D[i]-D[i+1])],
                                        dp[i][j] + 2);
                        }
                    } else {
                        ans = max(ans, dp[i][j]+1);
                    }
                }
            }
            //std::cout << "i: " << i << std::endl;
        }
        rep(i, 2200) {
            ans = max(ans, dp[n][i]);
        }
        return ans;
    }
};

int main()
{
    int2(n, k);
    vi data(n);
    rep(i, n) cin >> data[i];
    TypoCoderDiv1 solve;
    std::cout << solve.getmax(data, k) << std::endl;

    return 0;
}
