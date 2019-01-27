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


class Yllion
{ 
    public:
        vector<string> keta = {"one", "ten", "hundred", 
            "myriad", "myllion", "byllion", "tryllion",
            "quadryllion", "quintyllion", "sextyllion",
            "septyllion", "octyllion", "nonyllion", "decyllion"};

        int dec(vector<string> &data) {
            int ret = 0;
            rep(i, data.size()) {
                Rep(j, keta.size()) {
                    if (data[i] == keta[j]) {
                        ret += pow(2ll, j-1);
                    }
                }
            }
            return ret;
        }

        string enc(int data) {
            vector<string> ret;
            while (data) {
                for (int i = keta.size()-1; i > 0; i--) {
                    if (pow(2ll, i-1) <= data) {
                        //if (ret != "") ret += " ";
                        ret.pb(keta[i]);
                        data -= pow(2ll, i-1);
                    }
                }
            }
            reverse(all(ret));
            string ans = "";
            if (ret[0] == "ten") {
                ans = ret[0];
            } else {
                ans = "one ";
                ans += ret[0];
            }
            Rep(i, ret.size()) {
                ans += " ";
                ans += ret[i];
            }
            return ans;
        }

        string getPower(string a, string b) {
            if (a == "one") return b;
            if (b == "one") return a;
            vector<string> aa;
            string tmp;
            rep(i, a.size()) {
                if (a[i] == ' ') {
                    aa.pb(tmp);
                    tmp = "";
                } else {
                    tmp += a[i];
                }
            }
            aa.pb(tmp);
            /*rep(i, aa.size()) {
                cout << aa[i] << endl;
            }*/

            vector<string> bb;
            tmp = "";
            rep(i, b.size()) {
                if (b[i] == ' ') {
                    bb.pb(tmp);
                    tmp = "";
                } else {
                    tmp += b[i];
                }
            }
            bb.pb(tmp);
            /*rep(i, bb.size()) {
                cout << bb[i] << endl;
            }*/

            int aaa = dec(aa), bbb = dec(bb);
            return enc(aaa + bbb);
        }
};



int main()
{
    Yllion solve;
    //string st1; cin >> st1;
    //string st2; cin >> st2;

    //cout << solve.getPower(st1, st2) << endl;
    cout << solve.getPower(
            "ten hundred myriad myllion byllion tryllion quadryllion quintyllion sextyllion septyllion octyllion nonyllion",
            "ten hundred myriad myllion byllion tryllion quadryllion quintyllion sextyllion septyllion octyllion nonyllion")
        << endl;

    return 0;
}
