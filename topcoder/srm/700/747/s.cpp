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


class Sherlock
{ 
    public:
        string isItHim(string firstName, string lastName)
        {
            if (firstName.size() < 7 || lastName.size() < 7) {
                return "It is someone else";
            }
            if (firstName[0] != 'B' || lastName[0] != 'C') {
                return "It is someone else";
            }
            vi use1(30, 0);
            string mmn = "BENEDICT", mm = "CUMBERBATCH";
            rep(i, mmn.size()) {
                use1[mmn[i] - 'A'] = 1;
            }
            int cnt = 0;
            rep(i, firstName.size()) {
                cnt += use1[firstName[i] - 'A'];
            }
            if (cnt < 3) {
                return "It is someone else";
            }
            vi use2(30, 0);
            rep(i, mm.size()) {
                use2[mm[i] - 'A'] = 1;
            }
            cnt = 0;
            rep(i, lastName.size()) {
                cnt += use2[lastName[i] - 'A'];
            }
            if (cnt < 5) {
                return "It is someone else";
            }
            return "It is him";
        }
};



int main()
{
    Sherlock solve;
    string a, b; cin >> a >> b;
    cout << solve.isItHim(a, b) << endl;
    return 0;
}
