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
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

bool used[1010][1010], cave[1010][1010];
int prime[1001000], number[1010][1010];
int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
i_i kyoko[1001000];
i_i table[1010][1010];

void sieve()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    rep(i, 1001000) {
        if (prime[i]) {
            for (int j = 2; i * j < 1001000; j++) {
                prime[i*j] = false;
            }
        }
    }
}

void funami_yui()
{
    int move = 1, num = 1, cnt = 0, ptr = 0, x = 505, y = 505;
    kyoko[0] = {0LL, 0LL};
    rep(i, 1000500) {
        cave[x][y] = prime[num];
        kyoko[num] = {x, y};
        number[x][y] = num++;
        x += dx[ptr]; y += dy[ptr];
        cnt++;
        if (cnt == move) {
            ptr = (ptr + 1) % 4;
        } else if (cnt == move + move) {
            cnt = 0;
            move++;
            ptr = (ptr + 1) % 4;
        }
    }
}

void solve(int a, int b)
{
    memset(used, false, sizeof(used));
    memset(table, 0, sizeof(table));
    used[kyoko[b].fir][kyoko[b].sec] = true;
    table[kyoko[b].fir][kyoko[b].sec] = 
        (cave[kyoko[b].fir][kyoko[b].sec] ? i_i(1, b) : i_i(0, 0));
    for (int i = 2; i < 1008; i++) {
        for (int j = 2; j < 1008; j++) {
            if (used[i][j]) {
                int nxt, nnum;
                if (number[i+1][j-1] <= a) {
                    used[i+1][j-1] = true;
                    nxt = table[i][j].fir + (cave[i+1][j-1] ? 1LL : 0LL);
                    nnum = (cave[i+1][j-1] ? 
                            number[i+1][j-1] : table[i][j].sec);
                    if (table[i+1][j-1].fir < nxt) {
                        table[i+1][j-1] = {nxt, nnum};
                    } else if (table[i+1][j-1].fir == nxt) {
                        table[i+1][j-1].sec = 
                            max(table[i+1][j-1].sec, nnum);
                    }
                }
                if (number[i+1][j] <= a) {
                    used[i+1][j] = true;
                    nxt = table[i][j].fir + (cave[i+1][j] ? 1LL : 0LL);
                    nnum = (cave[i+1][j] ? 
                            number[i+1][j] : table[i][j].sec);
                    if (table[i+1][j].fir < nxt) {
                        table[i+1][j] = {nxt, nnum};
                    } else if (table[i+1][j].fir == nxt) {
                        table[i+1][j].sec = 
                            max(table[i+1][j].sec, nnum);
                    }
                }
                if (number[i+1][j+1] <= a) {
                    used[i+1][j+1] = true;
                    nxt = table[i][j].fir + (cave[i+1][j+1] ? 1LL : 0LL);
                    nnum = (cave[i+1][j+1] ? 
                            number[i+1][j+1] : table[i][j].sec);
                    if (table[i+1][j+1].fir < nxt) {
                        table[i+1][j+1] = {nxt, nnum};
                    } else if (table[i+1][j+1].fir == nxt) {
                        table[i+1][j+1].sec = 
                            max(table[i+1][j+1].sec, nnum);
                    }
                }
            }
        }
    }

    i_i ans = {-1, -1};
    rep(i, 1010) rep(j, 1010) {
        if (number[i][j] <= a) {
            if (ans.fir < table[i][j].fir) {
                ans = table[i][j];
            } else if (ans.fir == table[i][j].fir) {
                ans.sec = max(ans.sec, table[i][j].sec);
            }
        }
    }

    cout << ans.fir << " " << ans.sec << endl;

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    sieve();
    funami_yui();

    while (1) {
        int2(a, b);
        if (!a && !b) break;
        solve(a, b);
    }

    return 0;
}


