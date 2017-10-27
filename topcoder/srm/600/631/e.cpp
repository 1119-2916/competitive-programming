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


class TaroJiroGrid
{ 
    public:
        bool check(vector<string> &state)
        {
            int n = state.size();
            rep(j, state.size()) {
                int ptr = 0;
                Rep(i, state.size()) {
                    if (state[ptr][j] != state[i][j]) {
                        if (i - ptr > n/2) {
                            return false;
                        }
                        ptr = i;
                    }
                }
                if (ptr < n/2) return false;
            }
            return true;
        }
        vector<string> flip(vector<string> &state, int pos, char color)
        {
            int n = state.size();
            vector<string> ret = state;
            rep(i, n) {
                ret[pos][i] = color;
            }
            return ret;
        }
        void print(vector<string> state)
        {
            int n = state.size();
            rep(i, n) {
                rep(j, n) {
                    std::cout << state[i][j];
                }
                cout << endl;
            }
        }

        int getNumber(vector<string> grid)
        {
            int n = grid.size();
            if (check(grid)) return 0;
            int ret = -1;
            rep(i, n) {
                vector<string>  yui = flip(grid, i, 'B');
                if (check(yui)) return 1;
                for (int j = i+1; j < n; j++) {
                    vector<string>  kyoko = flip(yui, j, 'B');
                    if (check(kyoko)) ret = 2;
                                    kyoko = flip(yui, j, 'W');
                    if (check(kyoko)) ret = 2;
                }
                                yui = flip(grid, i, 'W');
                if (check(yui)) return 1;
                for (int j = i+1; j < n; j++) {
                    vector<string>  kyoko = flip(yui, j, 'B');
                    if (check(kyoko)) ret = 2;
                                    kyoko = flip(yui, j, 'W');
                    if (check(kyoko)) ret = 2;
                }
            }
            return ret;
        }
};



int main()
{
    int n;
    while (cin >> n) {
        vector<string> state(n);
        rep(i, n) cin >> state[i];
        rep(i, n) cout << state[i] << endl;
        TaroJiroGrid solve;
        std::cout << solve.getNumber(state) << std::endl;
    }

    return 0;
}
