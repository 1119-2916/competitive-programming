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


class PotentialArithmeticSequence
{ 
    public:
        vvb dp;
        int calc(vi d, int s, int e)
        {
            //std::cout << "call : (" << s << ", " << e << ") " << endl;
            int st = 0;
            Rep(i, 130) {
                if (dp[s][i]) {
                    int sst = st = i;
                    bool ok = true;
                    for (int j = s+1; j < e; j++) {
                        if (!dp[j][++st]) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        /*
                        std::cout << "sst" << sst << std::endl;
                        std::cout << sst << " ";
                        for (int j = s+1; j < e; j++) {
                            if (!dp[j][++sst]) {
                                ok = false;
                            }
                            std::cout << sst << " ";
                        }
                        cout << endl;*/
                        return 1;
                    }
                }
            }
            return 0;
        }

        int zerocount(int n)
        {
            int ret = 0;
            while (~n & 1) {
                ret++;
                n >>= 1;
            }
            return ret;
        }

        int numberOfSubsequences(vi d)
        {
            int ret = 0, n = d.size();
            dp = vvb(n, vb(300, false));
            rep(i, n) {
                d[i] = (d[i] < 7) ? d[i] : 7;
                for (int j = 1; j < 300; j++)
                    if ( d[i] == zerocount(j) ) dp[i][j] = true;
            }
            /*
            rep(i, n) {
                Rep(j, 130) {
                    if (!((j + 1) % 20)) cout << endl;
                    std::cout << dp[i][j] << " ";
                }
                cout << endl;
            }
            */
            rep(i, n) {
                for (int j = i+1; j <= n; j++) {
                    ret += calc(d, i, j);
                    //std::cout << calc(d, i, j) << std::endl;
                }
            }
            return ret;
        }

};



int main()
{
    int n;
    PotentialArithmeticSequence solve;
    while (cin >> n) {
        vi data(n);
        rep(i, n) cin >> data[i];
        std::cout << solve.numberOfSubsequences(data) << std::endl;
    }
    return 0;
}
