//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>
 
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

/*int dxy[5] = {0, 1, 0, -1, 0};
  assign
*/
bool eq(long double a, long double b)
{
    return ( -EPS < a-b && a-b < EPS );
}

 
signed main()
{
    Int(n);

    while (n) {
        vi in(n);
        rep(i, n) {
            cin >> in[i];
        }
        long double min = 1001000.0;
        int anss = 0, ansa = 0, ansc = 0;
        rep(s, 16) {
            rep(a, 16) {
                rep(c, 16) {
                    vi ex(256, 0);
                    int r = s;
                    rep(i, n) {
                        r = (a * r + c) % 256;
                        ex[(r + in[i]) % 256]++;
                    }
                    long double ret = 0.0;
                    rep(i, 256) {
                        long double d = (long double)ex[i] / (long double)n;
                        if (eq(d, 0.0)) {
                            continue;
                        } else {
                            ret -= d * log(d);
                        }
                    }
                    if (ret < min - EPS) {
                        min = ret;
                        anss = s;
                        ansa = a;
                        ansc = c;
                    }
                }
            }
        }
        cout << anss << " " << ansa << " " << ansc << endl;
        cin >> n;
    }

    return 0;
}

