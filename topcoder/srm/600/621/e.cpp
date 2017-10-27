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


class RadioRange
{ 
    public:
        double RadiusProbability(vi x, vi y, vi r, int z)
        {
            int n = x.size();
            vector< pair< long double, long double > > data(n);
            rep(i, n) {
                long double dist = x[i] * (ll)x[i] + y[i] * (ll)y[i];
                dist = sqrt(dist);
                data[i].fir = max(0.0L, min((long double)z, 
                            dist - (long double)r[i]));
                data[i].sec = min((long double)z, dist + (long double)r[i]);
            }
            /*
            rep(i, n) {
                printf("%.10Lf %.10Lf\n", data[i].fir, data[i].sec);
            }
            */
            sort(all(data));
            long double sum = 0.0, left = data[0].fir, right = data[0].sec;
            rep(i, n) {
                if (right < data[i].fir) {
                    sum += (right - left);
                    left = data[i].fir;
                    right = data[i].sec;
                }
                right = max(right, data[i].sec);
            }
            sum += (right - left);
            //printf("%.10Lf\n", sum);
            return (z - sum) / (long double)z;
        }
};



int main()
{
    RadioRange solve;
    int2(n, z);
    vi a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    printf("%.10lf\n", solve.RadiusProbability(a, b, c, z));

    return 0;
}
