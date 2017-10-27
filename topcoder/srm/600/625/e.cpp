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


class PalindromePermutations
{ 
    public:
        double palindromeProbability(string word)
        {
            int n = word.size(), sn = 0;
            int odd_num = 1;
            vi cnt(26, 0), use(26, 0);
            rep(i, n) {
                cnt[word[i] - 'a']++;
            }
            if (n % 2) {
                int tmp = 0;
                rep(i, cnt.size()) {
                    if (cnt[i] % 2) {
                        odd_num = cnt[i];
                        tmp++;
                        cnt[i]--;
                    }
                    use[i] = cnt[i] / 2;
                    sn += use[i];
                }
                if (tmp != 1) {
                    std::cout << "0.0000000000" << std::endl;
                    return 0;
                }
            } else {
                rep(i, cnt.size()) {
                    use[i] = cnt[i]/2;
                    if (cnt[i] % 2) {
                        std::cout << "0.0000000000" << std::endl;
                        return 0;
                    }
                    sn += use[i];
                }
            }
 //           std::cout << sn << std::endl;

            vi upper, lower;
            upper.pb(odd_num);
            rep(i, cnt.size()) {
                for (int j = cnt[i]; j > use[i]; j--) {
                    upper.pb(j);
//                    std::cout << j << " ";
                }
            }
//            cout << endl;
            for (int i = n; i > sn; i--) {
                lower.pb(i);
 //               std::cout << i << " ";
            }
//            cout << endl;


            double ans = 1.0;
            rep(i, min(upper.size(), lower.size())) {
                ans *= upper[i];
                ans /= lower[i];
            }
            for (int i = min(upper.size(), lower.size());
                    i < upper.size(); i++) {
                ans *= upper[i];
            }
            for (int i = min(upper.size(), lower.size());
                    i < lower.size(); i++) {
                ans /= lower[i];
            }
//            printf("%.10lf\n", ans);
            return ans;
        }
};



int main()
{
    string st;
    cin >> st;
    PalindromePermutations solve;
    std::cout << solve.palindromeProbability(st) << std::endl;

    return 0;
}
