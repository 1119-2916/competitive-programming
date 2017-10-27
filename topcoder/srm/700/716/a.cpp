#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

class Permutiple
{
    public:
        string isPossible(int x)
        {
            string st = to_string(x);
            int yui = x * 2;
            string kyoko = to_string(yui);
            sort(all(st));

            while (kyoko.size() == st.size()) {
                sort(all(kyoko));
                if (kyoko == st) {
                    return "Possible";
                }
                yui += x;
                kyoko = to_string(yui);
            }

            return "Impossible";
        }

};

 
signed main()
{

    return 0;
}

