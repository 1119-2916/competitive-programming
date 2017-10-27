#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 0.00000000001
#define ll long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define pb push_back
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int >
#define vvi vector<vi >
#define vd vector<double >
#define vvd vector<vd >
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


class FixedDiceGameDiv1
{ 
    public:
        double getExpectation(int a, int b, int c, int d)
        {
            if (a * b <= c) return -1.0;
            vvd table(2, vd(2501, 0));
            table[0][0] = table[1][0] = 1.0;
            for (int i = 0; i < a; i++) {
                for (int j = table[0].size()-1; j >= 0; j--) {
                    if (table[0][j]) {
                        Rep(k, b+1) {
                            table[0][j + k] += table[0][j] / b;
                        }
                        table[0][j] = 0.0;
                    }
                }
            }
            for (int i = 0; i < c; i++) {
                for (int j = table[1].size()-1; j >= 0; j--) {
                    if (table[1][j]) {
                        Rep(k, d+1) {
                            table[1][j + k] += table[1][j] / d;
                        }
                        table[1][j] = 0.0;
                    }
                }
            }

            double kyoko = 0.0, yui = 0.0;
            //for (int i = c+1; i <= a*b; i++) {
            rep(i, table[0].size()) {
                double tmp = 0.0;
                rep(j, i) {
                    tmp += table[1][j];
                }
                kyoko += tmp * i * table[0][i];
                yui += tmp * table[0][i];
            }
            return kyoko / yui;
        }
};



int main()
{
    int2(a, b);
    int2(c, d);

    FixedDiceGameDiv1 solve;
    std::cout << solve.getExpectation(a, b, c, d) << std::endl;

    return 0;
}
