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
#define in(x, a, b) ((a) <= (x) && (x) < (b))
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


class EllysCodeConstants
{ 
    private:
        char yui[5] = {'O', 'I', 'Z', 'S', 'T'};
        char kyoko[5] = {'0', '1', '2', '5', '7'};
        char funami_yui(char data)
        {
            rep(i, 5) {
                if (yui[i] == data) return kyoko[i];
            }
            if (in(data, 'A', 'G')) return data;
            return 0;
        }
        string toshino_kyoko(string input, string prefix, int p)
        {
            if (input.size() - p == 1) {
                if (input[p] == 'U') return prefix + "U";
                if (input[p] == 'L') return prefix + "L";
            } else if (input.size() - p == 2) {
                if (input[p] == 'L' && input[p+1] == 'L') return prefix + "LL";
                if (input[p] == 'U' && input[p+1] == 'L') return prefix + "UL";
                if (input[p] == 'L' && input[p+1] == 'U') return prefix + "LU";
            } else if (input.size() - p == 3) {
                if (input[p] == 'U' && input[p+1] == 'L' && input[p+2] == 'L') return prefix + "ULL";
                if (input[p] == 'L' && input[p+1] == 'L' && input[p+2] == 'U') return prefix + "LLU";
            }
            return "";
        }
    public: 
        string getLiteral(string candidate)
        {
            if (!candidate.size()) return "";

            string ret = "0x";
            int p = 0;
            for (; p < candidate.size(); p++) {
                if (candidate[p] == 'U' || candidate[p] == 'L') {
                    return toshino_kyoko(candidate, ret, p);
                } else {
                    char tmp = funami_yui(candidate[p]);
                    if (!tmp) return "";
                    ret += tmp;
                }
            }
            return ret;
        }
};



int main()
{
    EllysCodeConstants solve;
    string st;
    cin >> st;
    std::cout << solve.getLiteral(st) << std::endl;

    return 0;
}
