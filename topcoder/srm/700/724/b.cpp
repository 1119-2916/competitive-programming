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


class OrAndSumEasy
{ 
    public:
        string tostring(long long a, int keta)
        {
            string ret;
            rep(i, keta) {
                ret.pb( (a % 2) ? '1' : '0' );
                a /= 2;
            }
            return ret;
        }
        int keta(long long a)
        {
            int ret = 0;
            while (a) {
                ret++;
                a /= 2;
            }
            return ret;
        }
        string isPossible(long long o, long long s)
        {
            if (o == 0) {
                if (s == 0) {
                    return "po";
                } else {
                    return "impo";
                }
            } else if (o == 1) {
                if (1 <= s && s <= 2) {
                    return "po";
                } else {
                    return "impo";
                }
            } else if (o & 1ll) {
                if (s & 1ll) {
                    return isPossible(o >> 1, s >> 1);
                } else {
                    if (s == 0) {
                        return "impo";
                    } else {
                        return isPossible(o >> 1, (s >> 1)-1);
                    }
                }
            } else {
                if (s & 1ll) {
                    return "im";
                } else {
                    return isPossible(o >> 1, s >> 1);
                }
            }
        }
};



int main()
{
    long long a, b;
    cin >> a >> b;
    OrAndSumEasy solve;
    cout << solve.isPossible(a, b) << endl;

    return 0;
}
