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


class MinProduct
{ 
    public:
        ll add(ll a, int b)
        {
            a *= 10;
            a += b;
            return a;
        }

        long long findMin(vector <int> amount, int blank1, int blank2)
        {
            ll ret = 9001000100010001000;
            ll num1 = 0, num2 = 0;

            vi use = amount;
            rep(i, blank1) {
                rep(j, 10) {
                    if (use[j]) {
                        num1 = add(num1, j);
                        use[j]--;
                        break;
                    }
                }
            }
            rep(i, blank2) {
                rep(j, 10) {
                    if (use[j]) {
                        num2 = add(num2, j);
                        use[j]--;
                        break;
                    }
                }
            }
            ret = min(ret, num1 * num2);

            num1 = num2 = 0;
            use = amount;
            rep(i, blank2) {
                rep(j, 10) {
                    if (use[j]) {
                        num2 = add(num2, j);
                        use[j]--;
                        break;
                    }
                }
            }
            rep(i, blank1) {
                rep(j, 10) {
                    if (use[j]) {
                        num1 = add(num1, j);
                        use[j]--;
                        break;
                    }
                }
            }
            ret = min(ret, num1 * num2);

            num1 = num2 = 0;
            use = amount;
            int bl1 = blank1, bl2 = blank2;
            while (bl1 || bl2) {
                rep(j, 10) {
                    if (use[j] && bl1) {
                        num1 = add(num1, j);
                        use[j]--;
                        bl1--;
                        break;
                    }
                }
                rep(j, 10) {
                    if (use[j] && bl2) {
                        num2 = add(num2, j);
                        use[j]--;
                        bl2--;
                        break;
                    }
                }
            }
            ret = min(ret, num1 * num2);

            num1 = num2 = 0;
            use = amount;
            bl1 = blank1, bl2 = blank2;
            while (bl1 || bl2) {
                rep(j, 10) {
                    if (use[j] && bl2) {
                        num2 = add(num2, j);
                        use[j]--;
                        bl2--;
                        break;
                    }
                }
                rep(j, 10) {
                    if (use[j] && bl1) {
                        num1 = add(num1, j);
                        use[j]--;
                        bl1--;
                        break;
                    }
                }
            }
            ret = min(ret, num1 * num2);

            return ret;
        }
};



int main()
{
    int2(a, b);
    vi data(10);
    rep(i, 10) cin >> data[i];

    MinProduct solve;
    std::cout << solve.findMin(data, a, b) << std::endl;

    return 0;
}
