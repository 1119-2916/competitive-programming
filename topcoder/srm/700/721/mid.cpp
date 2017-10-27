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

ll table[10000];

class RememberWords
{ 
    public:
        void make_table()
        {
            for (ll i = 0; i < 10000; i++) {
                table[i] = i * (i + 1) / 2;
            }
        }
        int lb(ll a)
        {
            int l = 0, r = 9999;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (a < table[mid]) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return l;
        }
        string isPossible(int d1, int d2, int w1, int w2)
        {
            make_table();
            ll mina, minb, maxa, maxb;
            ll tmp = d1 * (d1-1LL) / 2LL;
            cout << tmp << " " << lb(w1) << " " << 
                (d1-1) + (w1-tmp)/d1 << endl << 
                (w1-tmp)/d1 << endl;
            if (w1 <= tmp) {
                maxa = lb(w1);
            } else {
                maxa = (d1-1) + (w1-tmp)/d1;
            }
            if (w1 < tmp) {
                mina = 0;
            } else {
                mina = (w1-tmp)/d1 + !!((w1-tmp)%d1);
            }
            //mina = max(0LL, (w1-tmp)/d1 + !!((w1-tmp)%d1));
            cout << "A : " << maxa << " " << mina << endl;

            tmp = d2 * (d2-1LL) / 2LL;
            cout << tmp << " " << lb(w2) << " " << 
                (d2-1) + (w2-tmp)/d2 << endl << 
                (w2-tmp)/d2 << endl;
            if (w2 <= tmp) {
                maxb = lb(w2);
            } else {
                maxb = (d2-1) + (w2-tmp)/d2;
            }
            if (w2 < tmp) {
                minb = 0;
            } else {
                minb = (w2-tmp)/d2 + !!((w2-tmp)%d2);
            }
            //minb = max(0LL, (w2-tmp)/d2 + !!((w2-tmp)%d2));
            cout << " B : " << maxb << " " << minb << endl;
            if ( (mina -1 <= minb && minb <= maxa +1) ||
                    (minb -1 <= mina && mina <= maxb +1)) {
                return "Possible";
            } else {
                return "Impossible";
            }
        }
};


int main()
{
    int2(a, b);int2(c, d);
    RememberWordsEasy solve;
    std::cout << solve.isPossible(a, b, c, d) << std::endl;

    return 0;
}





