#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
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
// matrix dinic next_combination topcoder
// stack size = 128 * 1024 * 1024


class MysticAndCandies
{ 
    public:
        int minBoxes(int C, int X, vector <int> low, vector <int> high)
        {
            int n = low.size();
            vp mind(n), maxd(n);
            rep(i, n) {
                mind[i].fir = low[i];
                mind[i].sec = high[i];

                maxd[i].fir = high[i];
                maxd[i].sec = low[i];
            }
            sort(all(mind));
            reverse(all(mind));
            sort(all(maxd));
            reverse(all(maxd));

            rep(i, n) {
                std::cout << mind[i].fir << " ";
            }
            cout << endl;
            rep(i, n) {
                std::cout << mind[i].sec << " ";
            }
            cout << endl;
            rep(i, n) {
                std::cout << maxd[i].fir << " ";
            }
            cout << endl;
            rep(i, n) {
                std::cout << maxd[i].sec << " ";
            }
            cout << endl;

            Rep(i, n+1) {
                std::cout << "count : " << i << std::endl;
                int get = 0;
                rep(j, i) {
                    get += mind[j].fir;
                }
                int tmp = 0;
                for (int j = i; j < n; j++) {
                    tmp += mind[j].sec;
                }
                std::cout << get << " " << tmp << std::endl;
                get += ( (C - tmp - get) > 0 ? (C - tmp - get) : 0);
                std::cout << get << std::endl;
                if (get >= X) {
                    return i;
                }
                get = 0;
                rep(j, i) {
                    get += maxd[j].sec;
                }
                tmp = 0;
                for (int j = i; j < n; j++) {
                    tmp += maxd[j].fir;
                }
                get += ( (C - tmp - get) > 0 ? (C - tmp - get) : 0);
                std::cout << get << std::endl;
                if (get >= X) {
                    return i;
                }
            }
            return -1;
        }
};



int main()
{
    int3(a, b, c);
    vi d(c), e(c);
    rep(i, c) {
        cin >> d[i];
    }
    rep(i, c) {
        cin >> e[i];
    }
    MysticAndCandies solve;
    std::cout << solve.minBoxes(a, b, d, e) << std::endl;

    return 0;
}
