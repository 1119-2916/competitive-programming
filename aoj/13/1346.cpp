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

int sp;
string data;

int calc();
int num();
int expr();
int factor();

signed main()
{
    cin >> data;
    Int(ans);
    sp = 0;
    int a = expr();
    sp = 0;
    int b = calc();
    if (a == ans && b == ans) {
        cout << "U" << endl;
    } else if (a == ans) {
        cout << "M" << endl;
    } else if (b == ans) {
        cout << "L" << endl;
    } else {
        cout << "I" << endl;
    }
    return 0;
}

int calc()
{
    int ret = num();
    while (sp < data.length() ) {
        if ( data[sp] == '*' ) {
            sp++;
            ret *= num();
        } else if ( data[sp] == '+' ) {
            sp++;
            ret += num();
        } else {
            break;
        }
    }
    return ret;
}

int expr()
{
    int ret = factor();
    while ( sp < data.length() ) {
        if (data[sp] == '+') {
            sp++;
            ret += factor();
        } else {
            break;
        }
    }
    return ret;
}

int factor()
{
    int ret = num();
    while ( sp < data.length() ) {
        if (data[sp] == '*' ) {
            sp++;
            ret *= num();
        } else {
            break;
        }
    }
    return ret;
}

int num()
{
    int ret = 0;
    while ( sp < data.length() ) {
        if ( '0' <= data[sp] && data[sp] <= '9' ) {
            ret *= 10;
            ret += data[sp++] - '0';
        } else {
            break;
        }
    }
    return ret;
}
