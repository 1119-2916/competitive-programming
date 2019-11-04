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
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

void put_left(vi &used, int *left_first, int *left_second)
{
    int targ = *left_first + 2;
    int n = used.size();
    if (targ <= n) {
        if (!used[targ-1] && (targ+1 > n || !used[targ])) {
            cout << targ << endl;
            used[targ-1] = 1;
            *left_first = targ;
            return ;
        }
    }
        for (int i = *left_second; i <= used.size(); i++) {
            if (!used[i-1]) {
                cout << i << endl;
                used[i-1] = 1;
                *left_second = i;
                return;
            }
        }
}

void put_right(vi &used, int *right_first, int *right_second)
{
    int targ = *right_first - 2ll;
    if (targ > 0) {
        if (!used[targ-1] && (targ-1 <= 0 || !used[targ-2])) {
            cout << targ << endl;
            *right_first = targ;
            used[targ-1] = 1;
            return ;
        }
    }
        for (int i = *right_second; i > 0; i--) {
            if (!used[i-1]) {
                cout << i << endl;
                used[i-1] = 1;
                *right_second = i;
                return;
            }
        }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    string st;
    cin >> st;


    int left_first = 0, right_first = n+1, 
        left_second = 1, right_second = n;

    vi used(n, 0);
    rep(i, st.size()) {
        if (st[i] == 'L') {
            if (left_first == 0) {
                if (used[0]) {
                    cout << 2 << endl;
                    left_first = 2;
                    used[1] = 1;
                } else {
                    cout << 1 << endl;
                    left_first = 1;
                    used[0] = 1;
                }
            } else {
                put_left(used, &left_first, &left_second);
            }
        } else {
            if (right_first == n+1) {
                if (used[n-1]) {
                    cout << n-1 << endl;
                    right_first = n-1;
                    used[n-2] = 1;
                } else {
                    cout << n << endl;
                    right_first = n;
                    used[n-1] = 1;
                }
            } else {
                put_right(used, &right_first, &right_second);
            }
        }
    }
    return 0;
}
