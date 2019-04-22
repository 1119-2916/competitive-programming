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


class EllysTicketPrices
{ 
    private:
        long double yui(long double p)
        {
            p *= (long double)100.0;
            long long d = round(p);
            return d / (long double)100.0;
        }
        int funami_yui(vi &data, double p, double t)
        {
            cout << "call : ";
            rep(i, data.size()) {
                std::cout << p << " ";
                p = yui((p * (100.0 / (100.0 + data[i]))));
            }
            cout << p << endl;
            if (p == t) return 0;
            if (p > t) return 1;
            //if (p < t) return -1;
            return -1;
        }
    public:
        double getPrice(int n, vector <int> C, int target)
        {
            vector<long double> B;
            double Ta = target;
            rep(i, n) {
                B.pb(C[i]);
            }
            long double l = 0, r = 200000, t;
            while (r - l > 0.01) {
                t = (l + r) / 2;
                t *= 100;
                t = round(t);
                t /= 100;
                double tp = t;
                double v = t;
                rep(y, n-1) {
                    t = t * (100 + B[y]) / 100;
                    t *= 100;
                    t = round(t);
                    t /= 100;
                    v += t;
                }
                v /= n;
                v *= 100;
                v = round(v);
                v /= 100;
                if (fabs(Ta - v) < 0.0000001) {
                    return tp;
                } else if (v > target) r = tp;
                else l = tp;
            }
            return r;
        }
        /*
            long double left = 0.0, right = 2100000000.0l;
            long double mm = 1;
            rep(i, C.size()) mm = (mm * 100.0 / (100.0 + C[i]));
            std::cout << mm << std::endl;
            while (1) {
                cout << left << " " << right << " " << yui((left + right) / (long double)2.0) << endl;
                //int state = funami_yui(C, yui((left + right) / 2.0), target);
                long double state = yui(mm * (left + right) / (long double)2.0);
                if (state == (long double)target) break;
                if (state - target > 0) {
                    right = (left + right) / (long double)2.0;
                }
                if (state - target < 0) {
                    left = (left + right) / (long double)2.0;
                }
            }
            return yui((left + right) / 2.0l);
            for (double p = left; p < right; p += 0.01) {
                cout << funami_yui(C, p, target) << endl;
                if (!funami_yui(C, p, target)) return p;
            }
            return 0.0;
            */
};



int main()
{
    EllysTicketPrices solve;
    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n-1; i++) {
        cin >> data[i];
    }
    Int(targ);
    std::cout << solve.getPrice(n, data, targ) << std::endl;

    return 0;
}
