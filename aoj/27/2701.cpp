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

int H = 2, W = 2;

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool _moveable(int x, int y, int dir)
{
    //cout << "call _move : " << x << " " << y << " " << dir;
    int nx = x + dx[dir], ny = y + dy[dir];
    //cout << " -> (" << nx << ", " << ny << ")";
    //cout << " : " << (in(nx, 0, H) && in(ny, 0, W)) << endl;
    return (in(nx, 0, H) && in(ny, 0, W));
}

bool movable(vector<vvi> &block, int dir)
{
    bool state = true;
    rep(i, block.size()) rep(j, block[i].size()) rep(k, block[i][j].size()) {
        if (block[i][j][k]) state &= _moveable(j, k, dir);
    }
    return state;
}

vector<vvi> put(vector<vvi> table, const vector<vvi> &cube, int dir)
{
    auto ret = table;
    rep(i, cube.size()) rep(j, cube[i].size()) rep(k, cube[i][j].size()) {
        if (cube[i][j][k]) {
            ret[i][j+dx[dir]][k+dy[dir]] = 1;
        }
    }
    return ret;
}

vector<vvi> drop(vector<vvi> &table, vector<vvi> &cube, int dir)
{
    vector<vvi> nc(cube.size(), vvi(cube[0].size(), vi(cube[0][0].size(), 0)));
    rep(i, cube.size()) rep(j, cube[i].size()) rep(k, cube[i][j].size()) {
        if (cube[i][j][k]) {
            nc[i][j+dx[dir]][k+dy[dir]] = 1;
        }
    }
    {
        bool fl = true;
        rep(j, nc[1].size()) rep(k, nc[1][j].size()) {
            fl &= !nc[1][j][k];
        }
        if (fl) {
            rep(j, nc[0].size()) rep(k, nc[0][j].size()) {
                nc[1][j][k] = nc[0][j][k];
                nc[0][j][k] = 0;
            }
        }
    }

    auto ret = table;
    int droph = 1;
    Rep(hi, table.size()-2) {
        bool fl = true;
        rep(i, nc.size()) rep(j, nc[i].size()) rep(k, nc[i][j].size()) {
            fl &= (!table[i+hi+1][j][k] || !nc[i][j][k]);
        }
        if (fl) {
            droph = hi;
        } else {
            break;
        }
    }

    rep(i, nc.size()) rep(j, nc[i].size()) rep(k, nc[i][j].size()) {
        ret[i+droph+1][j][k] += nc[i][j][k];
    }
    return ret;
}

void slide(vector<vvi> &table)
{
    for (int i = table.size()-2; i >= 0; i--) {
        bool can = true, ari = false;
        rep(j, table[i].size()) rep(k, table[i][j].size()) {
            can &= !(table[i+1][j][k]);
            ari |= table[i][j][k];
        }
        if (can && ari) {
            for (; i >= 0; i--) {
                rep(j, table[i].size()) rep(k, table[i][j].size()) {
                    table[i+1][j][k] = table[i][j][k];
                    table[i][j][k] = 0;
                }
            }
            i = table.size()-1;
        }
    }
}

int clear(vector<vvi> &table)
{
    int ret = 0;
    rep(i, table.size()) {
        int fl = true;
        rep(j, table[i].size()) rep(k, table[i][j].size()) {
            fl &= table[i][j][k];
        }
        if (fl) {
            rep(j, table[i].size()) rep(k, table[i][j].size()) {
                table[i][j][k] = 0;
            }
            slide(table);
            ret += 4;
            i--;
        }
    }
    return ret;
}

void print(vector<vvi> &table)
{
    rep(i, table.size()) {
        cout << "====== " << i << " ======" << endl;
        rep(j, table[i].size()) {
            rep(k, table[i][j].size()) {
                cout << table[i][j][k];
            }
            cout << endl;
        }
    }
}


int solve(vector<vector<vvi>> &cube, vector<vvi> &table, int cnum)
{
    auto edit = table;
    //cout << "call solve : " << cnum << endl;
    if (cnum == cube.size()) {
        return 0;
    }
    int ret = 0;
    for (int i = 0; i < 9; i++) {
        //cout << "move : " << i << " " << movable(cube[cnum], i) << endl;
        if (movable(cube[cnum], i)) {
            //edit = put(table, cube[cnum], i);
            edit = drop(table, cube[cnum], i);
            int tmp = clear(edit);
            //print(edit);
            ret = max(ret, tmp + solve(cube, edit, cnum+1));
        }
    }
    return ret;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int h, n;
    while (cin >> h >> n, n) {
        vector<vvi> table(50, vvi(2, vi(2, 0)));
        vector<vector<vvi>> cube(n, vector<vvi>(2, vvi(2, vi(2, 0))));
        rep(i, h) {
            rep(j, 2) {
                string tmp;
                cin >> tmp;
                rep(k, 2) {
                    table[table.size()-1-i][j][k] = (tmp[k] == '#');
                }
            }
        }

        rep(cnum, n) {
            for (int i = 1; i >= 0; i--) rep(j, 2) {
                string tmp;
                cin >> tmp;
                rep(k, 2) {
                    cube[cnum][i][j][k] = (tmp[k] == '#');
                }
            }
        }

        /*
        rep(cnum, n) {
            cout << "====== " << cnum << " ======" << endl;
            rep(i, cube[cnum].size()) {
                rep(j, cube[cnum][i].size()) {
                    rep(k, cube[cnum][i][j].size()) {
                        cout << cube[cnum][i][j][k];
                    }
                    cout << endl;
                }
            }
        }
        */

        cout << solve(cube, table, 0) / 4 << endl;
    }

    return 0;
}
