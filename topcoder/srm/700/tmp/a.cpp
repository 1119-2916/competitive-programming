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

class NewBanknote
{ 
    public:
        int cent[15] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
        int cs = 15;
        int pay(int p, vi &data)
        {
            int ret = 0;
            for (int i = data.size()-1; i >= 0; i--) {
                int tmp = p / data[i];
                ret += tmp;
                p -= data[i] * tmp;
            }
            return ret;
        }
        int find(int n) {
            int cnt = 0;
            int ind = cs-1;
            while (n > 0) {
                cnt += n / cent[ind];
                n %= cent[ind];
                --ind;
            }
            return cnt;
        }
        vi enemy(int n, vi &Amo) {
            vi result;
            for (int amo : Amo) {
                int maincount = find(amo);
                int minn = maincount;
                for (int i = 1; i < maincount && i <= amo / n; i++) {
                    int res = i * find(amo - i * n);
                    if (res < minn) {
                        minn = res;
                    }
                }
                result.push_back(minn);
            }
            cout << "ok" << endl;
            return result;
        }
        vector <int> fewestPieces(int newBanknote, vector <int> amountsToPay)
        {
            vi funami;
            rep(i, cs) {
                funami.pb(cent[i]);
            }
            funami.pb(newBanknote);

            sort(all(funami));

            vi dp(100001, INF);
            dp[0] = 0;
            rep(i, dp.size()) {
                rep(j, funami.size()) {
                    if (i + funami[j] < dp.size()) {
                        dp[i+funami[j]] = min(dp[i+funami[j]], dp[i] + 1);
                    }
                }
            }

            vi yui;
            rep(i, amountsToPay.size()) {
                int ret = INF;
                rep(j, min(amountsToPay[i]+1, (int)dp.size())) {
                    ret = min(ret, dp[j] + pay(amountsToPay[i] - j, funami));
                }
                yui.pb(ret);
            }
            return yui;
        }
};



int main()
{
    NewBanknote solve;
    int n, m;
    while (cin >> m >> n) {
        vector<int> data(n);
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }
        vi out1 = solve.enemy(m, data);
        vi out2 = solve.fewestPieces(m, data);
        rep(i, out1.size()){
            if (out1[i] != out2[i]) {
                cout << n << " " << data[i] << endl;
                return 0;
            }
        }
        cout << "ok" << endl;
    }

    return 0;
}
