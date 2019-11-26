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

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);

    vi state(2 * n, 0);

    int result = 0;
    cout << "? ";
    rep(i, n) cout << i+1 << " ";
    cout << endl;

    {
        string st;
        cin >> st;
        if (st == "Red") result = 1;
        else if (st == "Blue") result = -1;
    }

    int p = 0;
    Rep(i, n) {
        cout << "? ";
        rep(j, n) {
            cout << i + j+1 << " ";
        }
        cout << endl;
        string st;
        cin >> st;
        int res = 0;
        if (st == "Red") res = 1;
        else if (st == "Blue") res = -1;
        if (res != result) {
            p = i;
            state[i-1] = result;
            state[i+n-1] = res;
            break;
        }
    }

    //rep(i, state.size()) cout << state[i] << " ";
    //cout << endl;
    //cout << p << endl;

    rep(i, state.size()) {
        //cout << "call : " << i << " " << p << " " << p+n-1 << endl;
        if (!state[i] && !(in(i, p, p+n-1))) {
            cout << "? " << i+1 << " ";
            rep(j, n-1) {
                cout << p + j+1 << " ";
            }
            cout << endl;
            string st;
            cin >> st;
            int res = 0;
            if (st == "Red") state[i] = 1;
            else if (st == "Blue") state[i] = -1;
        }
    }

    rep(i, state.size()) {
        if (!state[i]) {
            int b = 0, r = 0;
            cout << "? " << i+1 << " ";
            rep(j, state.size()) {
                if (b < n/2 && state[j] == -1) {
                    b++;
                    cout << j+1 << " ";
                }
                if (r < n/2 && state[j] == 1) {
                    r++;
                    cout << j+1 << " ";
                }
            }
            cout << endl;
            string st;
            cin >> st;
            int res = 0;
            if (st == "Red") state[i] = 1;
            else if (st == "Blue") state[i] = -1;
        }
    }

    cout << "! ";
    rep(i, state.size()) {
        cout << (state[i] == -1 ? "B" : "R");
        if (!state[i]) assert(0);
    }
    cout << endl;



    return 0;
}

