#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
vector<string> str(1001);
vvi tag(1001);

void print(int pos, int level);

signed main()
{
    Int(n);
    Rep(i, n+1) {
        int tmp;
        cin >> tmp >> str[i];
        tag[tmp].pb(i);
    }
    print(0, 0);
    return 0;
}

void print(int pos, int level)
{
    rep(i, tag[pos].size()) {
        rep(k, level) {
            cout << '.';
        }
        cout << str[tag[pos][i]] << endl;
        print(tag[pos][i], level+1);
    }
}

