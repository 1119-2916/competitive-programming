#include <bits/stdc++.h>

using namespace std;

#define INF 2010001000
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


class CatsOnTheLineDiv1
{ 
    public:
        int getNumber(vi position, vi count, int t)
        {
            int n = position.size(), ret = 0;
            vp state(n);
            rep(i, n) {
                state[i].fir = position[i];
                state[i].sec = count[i];
            }
            sort(all(state));
            int left = -INF, rest = -INF;
            rep(i, n) {
                if (state[i].fir - t <= rest) continue;
                int right;
                if (i != n-1) right = state[i+1].fir-1;
                else right = INF;
                int range = min(right, state[i].fir+t) - 
                    max(left, state[i].fir-t-1);
                if (range >= state[i].sec) {
                    left = max(left, state[i].fir-t-1) + state[i].sec;
                } else {
                    rest = state[i].fir + t;
                    ret++;
                }
            }
            /*
                std::cout << "pos : " <<  left << " " << right << " ";
                state[i].sec -= min(t, state[i].fir - left);
                if (state[i].sec > 0) {
                    int tmp = min(t, right - state[i].fir);
                    if (state[i].sec - tmp > 0) {
                        left = state[i].fir + tmp;
                        if (lest && right <= left) {
                            lest = false;
                            state[i].sec = 0;
                        }
                    } else {
                        left = state[i].fir + state[i].sec-1;
                    }
                    state[i].sec -= tmp;
                } else {
                    left = state[i].fir + state[i].sec - 1;
                }
                //ret += max(0, state[i].sec-1);
                if (state[i].sec > 1) {
                    ret++;
                    rest = true;
                }
                std::cout << ret << std::endl;
            }
            */
            return ret;
        }
};



int main()
{
    int n, t;
    while (cin >> n >> t) {
        vi a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        std::cout << "===dataset===" << std::endl;
        std::cout << n << " " << t << std::endl;
        rep(i, n) cout << a[i] << " ";
        cout << endl;
        rep(i, n) cout << b[i] << " ";
        cout << endl;
        std::cout << "============" << std::endl;
        CatsOnTheLineDiv1 solve;
        std::cout << solve.getNumber(a, b, t) << std::endl;
    }


    return 0;
}
