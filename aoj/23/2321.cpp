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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

typedef struct data{
    int num, value;
    vector< i_i > time;
}data;

int n, ans;
data input[100];

void dfs(int st, int table, int score);

signed main()
{
    while (cin >> n, n) {
        memset(input, 0, sizeof(input));
        rep(i, n) {
            cin >> input[i].num >> input[i].value;
            rep(j, input[i].num) {
                int a, b;
                cin >> a >> b;
                input[i].time.pb(mp(a, b));
            }
        }
        ans = 0;
        dfs(0, 0, 0);
        cout << ans << endl;
    }

    return 0;
}

void dfs(int st, int table, int score)
{
    //cout << st << endl;
    //rep(i, 16) { cout << (table >> i) % 2 << " "; } cout << endl;
    bool fl = true;
    int ntable = table;
    ans = max(ans, score);
    if (st == n) { return ; }
    rep(i, input[st].num) {
        for (int j = input[st].time[i].first;
                j < input[st].time[i].second; j++) {
            int tmp = 1 << (j-6);
            if (table & tmp) {
                fl = false;
            } else {
                ntable |= tmp;
            }
        }
    }
    if (fl) { 
        dfs(st+1, ntable, score + input[st].value);
    }
    dfs(st+1, table, score);
}
