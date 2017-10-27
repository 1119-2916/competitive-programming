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


class RectangleCovering
{ 
    public:
        int minimumNumber(int hh, int hw, vi ah, vi aw)
        {
            int n = ah.size();
            vi ok_h, ok_w;
            rep(i, n) {
                if (hh < ah[i] && hh < aw[i]) {
                    ok_h.pb(max(ah[i], aw[i]));
                } else if (hh < ah[i] || hh < aw[i]) {
                    ok_h.pb(min(ah[i], aw[i]));
                }
            }
            rep(i, n) {
                if (hw < ah[i] && hw < aw[i]) {
                    ok_w.pb(max(ah[i], aw[i]));
                } else if (hw < ah[i] || hw < aw[i]) {
                    ok_w.pb(min(ah[i], aw[i]));
                }
            }
            sort(all(ok_w));
            sort(all(ok_h));
            reverse(all(ok_h));
            reverse(all(ok_w));
            /*
            rep(i, ok_w.size()) 
                std::cout << ok_w[i] << " ";
            cout << endl;

            rep(i, ok_h.size()) 
                std::cout << ok_h[i] << " ";
            cout << endl;
            */
            int ret_w = 0, sum = 0;
            bool funami = false;
            rep(i, ok_w.size()) {
                sum += ok_w[i];
                ret_w++;
                if (sum >= hh) {
                    funami = true;
                    break;
                }
            }
            if (!funami) ret_w = INF;

            int ret_h = 0;
            funami = false;
            sum = 0;
            rep(i, ok_h.size()) {
                sum += ok_h[i];
                ret_h++;
                if (sum >= hw) {
                    funami = true;
                    break;
                }
            }

            if (!funami) ret_h = INF;
            if (ret_w == INF && ret_h == INF) {
                return -1;
            }
            return min(ret_w, ret_h);
        }
};



int main()
{
    int2(h, w);
    Int(n);
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    RectangleCovering solve;
    std::cout << solve.minimumNumber(h, w, a, b) << std::endl;


    return 0;
}
