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


class HappyLetterDiv1
{ 
    public:
        vi cnt;
        
        bool funami_yui()
        {
            int sum = 0, freq = 0;
            rep(i, 26) {
                freq = max(freq, cnt[i]);
                sum += cnt[i];
            }
            if (sum % 2) return false;
            if (freq > sum / 2) return false;
            return true;
        }

        void print()
        {
            rep(i, 26) {
                if (cnt[i]) {
                    std::cout << (char)(i + 'a') << cnt[i] << " ";
                }
            }
            cout << endl;
        }

        string getHappyLetters(string letters)
        {
            int n = letters.size();
            cnt = vi(26, 0);
            rep(i, n) {
                cnt[letters[i] - 'a']++;
            }
            string ret;
            rep(i, 26) {
                for (int j = 1; j <= cnt[i]; j++) {
                    cnt[i] -= j;
                    //print();
                    if (funami_yui()) {
                        ret.pb(i + 'a');
                        cnt[i] += j;
                        break;
                    }
                    cnt[i] += j;
                }
            }
            return ret;
        }
};



int main()
{
    string st;
    cin >> st;
    HappyLetterDiv1 solve;
    std::cout << solve.getHappyLetters(st) << std::endl;

    return 0;
}
