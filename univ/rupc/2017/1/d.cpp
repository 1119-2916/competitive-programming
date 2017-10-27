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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

vector <vector < i_i > > pos;
vector <string> str;
int n;
string data;

string solve();
bool search(string a);
bool search(string a);
void make();

signed main()
{
    cin >> n;
    pos.assign(26, vector< i_i >());
    rep(i, n) {
        string tmp;
        cin >> tmp;
        str.pb(tmp);
        rep(j, tmp.size()) {
            pos[tmp[j]-'a'].pb(mp(i, j));
        }
    }

    cout << solve() << endl;

    return 0;
}

string solve()
{
    data = "a";
    rep(i, 26*26*26*26) {
        //cout << data << endl;
        if (search(data)) {
            return data;
        }
        make();
    }
}

void make()
{
    if (data == "z" || data == "zz" || 
            data == "zzz") {
        rep(i, data.size()) {
            data[i] = 'a';
        }
        data.pb('a');
    } else {
        for (int i = data.size() -1; i >= 0; i--) {
            if (data[i] == 'z') {
                data[i] = 'a';
            } else {
                data[i]++;
                break;
            }
        }
    }
}


bool search(string a)
{
    for (i_i i : pos[a[0] - 'a']) {
        if (str[i.first].size() - i.second < a.size()) {
            continue;
        } else {
            bool ret = true;
            rep(j, a.size()) {
                if (str[i.first][i.second+j] != a[j]) {
                    ret = false;
                    break;
                }
            }
            if (ret) {
                return false;
            }
        }
    }
    return true;
}




