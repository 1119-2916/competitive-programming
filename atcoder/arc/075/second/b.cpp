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
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

int lb(int life, int yui, int kyoko, int num)
{
    if (life <= num * kyoko)
        return 0;
    int l = 0, r = num;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if ( (num - mid) * kyoko + mid * yui >=
                life) {
            r = mid;
        } else {
            l = mid;
        }
    }
        int mid = (l + r) / 2;
        if ( (num - mid) * kyoko + mid * yui >=
                life) {
            return l;
        } else {
            return r;
        }
}


signed main()
{
    Int(n);
    int2(a, b);
    vi data(n);
    rep(i, n) {
        cin >> data[i];
    }

    int l = 1, r = 1010001000;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int atk = mid * b;

        int cnt = 0;
        rep(i, n) {
            cnt += lb(data[i], a, b, mid);
        }

        if (cnt <= mid) { // 成功
            r = mid;
        } else {
            l = mid;
        }
    }


        int atk = l * b;

        int cnt = 0;
        rep(i, n) {
            cnt += lb(data[i], a, b, l);
        }

        if (cnt <= l) {
            cout << l << endl;
        } else {
            cout << r << endl;
        }



    return 0;
}

