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


class DivisorsPower
{ 
    public:

        vector< pair<ll, ll> > funami_yui(ll n)
        {
            vector< pair<ll, ll> > ret;
            for (ll i = 2; i * i <= n; i++) {
                if (!(n % i)) {
                    ll cnt = 0;
                    while (!(n % i)) {
                        n /= i;
                        cnt++;
                    }
                    ret.pb(i_i(i, cnt));
                }
            }
            return ret;
        }

        int func(ll a, ll b)
        {
            int ret = 0;
            while (!(a % b)) {
                a /= b;
                ret++;
            }
            if (a == 1) {
                return ret;
            } else {
                return 0;
            }
        }
            
        ll calc(ll a)
        {
            ll cnt = 2;
            for (ll i = 2; i * i <= a; i++) {
                if (!(a % i)) {
                    cnt++;
                    if (i * i != a) cnt++;
                }
            }
            return cnt;
        }

        long long findArgument(long long n)
        {
            for (ll i = 2; i * i * i <= n; i++) {
                if (!(n % i)) {
                    if (func(n, i)) {
                        if (pow(i, calc(i)) == n) {
                            return i;
                        }
                    }
                }
            }

            double sq = sqrt(n);
            for (ll i = max(2LL, (ll)(sq-3)); i <= sq+3; i++) {
                if (!(n % i)) {
                    if (func(n, i)) {
                        if (pow(i, calc(i)) == n) {
                            return i;
                        }
                    }
                }
            }

            return -1;
        }
};



int main()
{
    ll n;
    cin >> n;
    DivisorsPower solve;
    std::cout << solve.findArgument(n) << std::endl;

    return 0;
}
