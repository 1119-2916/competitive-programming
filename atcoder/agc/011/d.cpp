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
#define eb emplece_back
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
 
void run(string &a);

signed main()
{
    int2(n, k);
    string str;
    cin >> str;
    map<string, int> foo;

    int i = 0;
    while (foo.find(str) != foo.end()) {
        foo.insert(mp(str, i++));
        run(str);
        if (i == k) {
            cout << str << endl;
            return 0;
        }
    }
    int cyc = i - foo.find(str)->second + 1;
    k -= i; k %= cyc;
    rep(j, k) {
        run(str);
    }
    cout << str << endl;

    return 0;
}

void run(string &a)
{
    int ptr = 0, dist = 1;
    while (0 <= ptr && ptr < a.size()) {
        if (a[ptr] == 'A') {
            a[ptr] = 'B';
            dist *= -1;
            ptr += dist;
        } else {
            a[ptr] = 'A';
            ptr += dist;
        }
    }
}

