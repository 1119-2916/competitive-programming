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
// matrix dinic next_combination topcoder lcm
// stack size = 128 * 1024 * 1024

//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
//最小公倍数
int lcm(int x, int y) { return x / gcd(x, y) * y; }
//最大公約数 複数個
int gcd(const vector<int> &v) {
    int ret = v[0];
    for (int i = 1; i < v.size(); i++)
        ret = gcd(ret, v[i]);
    return ret;
}
//最小公倍数 複数個
int lcm(const vector<int> &v) {
    int ret = v[0];
    for (int i = 1; i < v.size(); i++)
        ret = lcm(ret, v[i]);
    return ret;
}


class WakingUp
{ 
    public:

        int maxSleepiness(vi period, vi start, vi volume, int d)
        {
            int n = period.size();
            int lp = 1;
            rep(i, n) {
                lp = lcm(lp, period[i]);
            }
            int mst = 0;
            rep(i, n) {
                mst = max(mst, start[i]);
            }
            int value = 0;
            rep(i, n) {
                value += lp / period[i] * volume[i];
            }
            value = lp * d - value;
            /*
            std::cout << "state : " << 
                lp << " " << mst << " " << value << std::endl;
            */
            if (value < 0) {
                return -1;
            }
            vi sum(mst+lp, 0);
            rep(i, n) {
                for (int j = start[i]; j < sum.size(); j += period[i]) {
                    sum[j] += volume[i];
                }
            }
            /*
            rep(i, sum.size()) {
                std::cout << sum[i] << " ";
            }cout << endl;
            */
            for (int i = 50000; i >= 0; i--) {
            //for (int i = 3; i >= 0; i--) {
                //std::cout << "st : " << i << std::endl;
                int tmp = i;
                Rep(j, mst+lp) {
                    tmp += d;
                    tmp -= sum[j];
                    //std::cout << tmp << " ";
                    if (!tmp) {
                        return i;
                    }
                }
                //cout << endl;
            }
            return 0;
        }

};



int main()
{
    int2(n, d);
    vi a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    WakingUp solve;
    std::cout << solve.maxSleepiness(a, b, c, d) << std::endl;

    return 0;
}
