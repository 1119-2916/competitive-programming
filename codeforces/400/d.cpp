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

int used[100000], key[100000][2], n;
bool room[100000];

bool solve(int pos);

signed main()
{
    int m;
    cin >> n >> m;
    vb room(n);
    rep(i, n) {
        Int(tmp);
        room[i] = (tmp == 0); // rock == 0
    }
    memset(key, -1, sizeof(key));
    rep(i, n) {
        Int(x);
        rep(j, x) {
            Int(tmp);
            tmp--;
            if (key[tmp][0] == -1) {
                key[tmp][0] = i;
            } else {
                key[tmp][1] = i;
            }
        }
    }
    rep(i, n) {
        cout << key[i][0] << key[i][1] << endl;
    }
    memset(used, 0, sizeof(used));
    if (solve(0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

bool solve(int pos)
{
    if (pos == n) {
        return true;
    }
    bool ret = false;
    if (room[pos]) {
        if (used[key[pos][1]] == -1) {
            if (used[key[pos][0]] == -1) {
                return false;
            } else {
                used[key[pos][0]] = 1;
                ret |= solve(pos+1);
                used[key[pos][0]] = 0;
            }
        } else {
            if (used[key[pos][0]] == -1) {
                used[key[pos][1]] = 1;
                ret |= solve(pos+1);
                used[key[pos][1]] = 0;
            } else {
                used[key[pos][1]] = 1;
                ret |= solve(pos+1);
                used[key[pos][1]] = 0;
            }
        }
    } else {
        if (used[key[pos][0]] == -1 && used[key[pos][1]] == 1 || 
            used[key[pos][0]] == 1 && used[key[pos][1]] == -1) {
            return false;
        } else {
            if (used[key[pos][0]] == -1 && used[key[pos][1]] == -1) {
                ret |= solve(pos+1);
            } else {
                used[key[pos][0]] = 1;
                used[key[pos][1]] = 1;
                ret |= solve(pos+1);
                used[key[pos][0]] = 0;
                used[key[pos][1]] = 0;
            }
        }
    }
    return ret;
}



