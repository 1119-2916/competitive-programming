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


class PairProduct
{ 
    public:
        vector <int> findPair(int n, int a0, int step, long long p) {
            if (p == a0) {
                vi ans; ans.pb(0); ans.pb(0);
                return ans;
            }
            long long STEP = step, A0 = a0;
            if (step == 0 && A0 * A0 == p) {
                vi ans; ans.pb(0); ans.pb(0);
                return ans;
            }
            rep(i, n) {
                long long mm = STEP * STEP * i + STEP * A0;
                long long mmn = p - A0 * A0 - i * STEP * A0;
                cout << i << " " << mm << " " << mmn << endl;
                if (mm == 0) continue;
                if (mmn % mm == 0 && mmn / mm < n && mmn / mm >= 0) {
                    vi ans;
                    ans.pb(i);
                    ans.pb(mmn / mm);
                    return ans;
                }
            }
            vi tmp(0, 0);
            return tmp;
        }
};



int main()
{
    PairProduct solve;

    int3(a, b, c);
    long long int pp; cin >> pp;

    vi hoge = solve.findPair(a, b, c, pp);
    rep(i, hoge.size()) {
        cout << hoge[i] << " ";
    }cout << endl;

    return 0;
}
