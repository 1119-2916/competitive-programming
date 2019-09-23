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

int prime[3001000];
void table()
{
    int n = 3000000;
    prime[0] = prime[1] = 1;
    for (int i = 2; i < n; i++) {
        if (!prime[i]) {
            for (int j = 2; i * j < n; j++) {
                prime[i * j] = 1;
            }
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    table();
    map<int, int> mm;
    for (int i = 0; i < 3000000; i++) {
        if (!prime[i]) {
            if (mm.find(i-2) != mm.end()) {
                mm[i] = mm[i-2] + 1;
            } else {
                mm[i] = 1;
            }
        }
    }

    int x = 0;
    for (int i = 0; i < n; i++) {
        if (mm.find(data[i]) != mm.end()) {
            x ^= mm[data[i]];
        }
    }


    if (x) {
        cout << "An" << endl;
    } else {
        std::cout << "Ai" << std::endl;
    }

    return 0;
}

