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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
int calc(char c);
int play(int dealer, string *data);

char mark;

signed main()
{
    while ( cin >> mark, mark != '#' ) {
        string input[13][4];
        rep(i, 4) {
            rep(j, 13) {
                cin >> input[j][i];
            }
        }
        //cout << "input finished." << endl;
        int ns = 0, ew = 0;
        int dealer = 3;
        rep(turn, 13) {
            dealer = play(dealer, input[turn]);
            //cout << dealer << endl;
            if (dealer % 2) {
                ew++;
            } else {
                ns++;
            }
        }
        cout << ((ns < ew) ? "EW" : "NS" ) << " " <<
            max(ns, ew) - 6 << endl;
    }
    return 0;
}
        
int play(int dealer, string *data)
{
    char start = data[dealer][1];
    int max = 0, ret = dealer;
    //cout << start << " ";
    rep(i, 4) {
        //cout << data[i] << " " ;
        if (data[i][1] == mark) {
            int tmp = calc(data[i][0]) + 100;
            //cout << tmp << " ";
            if (tmp > max) {
                ret = i;
                max = tmp;
            }
        } else if (data[i][1] == start) {
            int tmp = calc(data[i][0]);
            //cout << tmp << " ";
            if (tmp > max) {
                max = tmp;
                ret = i;
            }
        }
    }
    //cout << endl;
    return ret;
}

int calc(char c)
{
    if ( '2' <= c && c <= '9') {
        return c - '0';
    } else if (c == 'T') {
        return 10;
    } else if (c == 'J') { 
        return 11;
    } else if (c == 'Q') { 
        return 12;
    } else if (c == 'K') { 
        return 13;
    } else if (c == 'A') { 
        return 14;
    } else {
        return 0;
    }
}


