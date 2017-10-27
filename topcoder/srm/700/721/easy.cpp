#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-7
#define PI 3.1415926535926535
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


class FlightDataRecorder
{ 
    public:
        double getDistance(vector <int> heading, vector <int> distance)
        {
            long double x = 0.0, y = 0.0;
            int n = heading.size();
            vector<long double> a(n), b(n);
            rep(i, heading.size()) {
                //cout << heading[i]*PI/180.0l << endl;
                a[i] = distance[i] * cos(heading[i]*PI/180.0l);
                b[i] = distance[i] * sin(heading[i]*PI/180.0l);
                /*
                x += distance[i] * cos(heading[i]*PI/180.0l);
                y += distance[i] * sin(heading[i]*PI/180.0l);
                */
                //cout << x << " " << y << endl;
            }
            //cout << x << " " << y << endl;
            //x = 0.0; y = 0.0;
            rep(i, n) {
                x += a[i];
                y += b[i];
                //cout << a[i] << " " << b[i] << endl;
                //cout << x << " " << y << endl;
                if (abs(x) < EPS) x = 0.0;
                if (abs(y) < EPS) y = 0.0;
            }
            cout << x << " " << y << endl;
            return sqrt((x * x) + (y * y));
        }
};



int main()
{
    Int(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    FlightDataRecorder solve;
    std::cout << solve.getDistance(a, b) << std::endl;

    return 0;
}
