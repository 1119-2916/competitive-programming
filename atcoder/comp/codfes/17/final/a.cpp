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
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string st;
    cin >> st;

    int state = 0;
    rep(i, st.size()) {
        if (state == 0) {
            if (st[i] == 'A') {
                state = 1;
            } else if (st[i] == 'K') {
                state = 2;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (state == 1) {
            if (st[i] == 'K') {
                state = 2;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (state == 2) {
            if (st[i] == 'I') {
                state = 3;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (state == 3) {
            if (st[i] == 'H') {
                state = 4;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (state == 4) {
            if (st[i] == 'A') {
                state = 5;
            } else if (st[i] == 'B') {
                state = 6;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (state == 5) {
            if (st[i] == 'B') {
                state = 6;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (state == 6) {
            if (st[i] == 'A') {
                state = 7;
            } else if (st[i] == 'R') {
                state = 8;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (state == 7) {
            if (st[i] == 'R') {
                state = 8;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (state == 8) {
            if (st[i] == 'A') {
                state = 9;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (state == 8 || state == 9)
        cout << "YES" << endl;
    else cout << "NO" << endl;




    return 0;
}



