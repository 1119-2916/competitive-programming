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
 
signed main()
{
    Int(n);
    vi data1(n);
    vi data2(n);
    rep(i, n) {
        cin >> data1[i];
        data2[i] = data1[i];
    }


    int k = (n-1) % 4;
    int n1 = n, minus = 1;
    while (k--) {
        rep(i, n1-1) {
            data1[i] += data1[i+1] * minus;
            minus *= -1;
        }
        n1--;
        /*
        rep(i, n1) cout << data1[i] << " ";
        cout << endl;
        */
    }
    k = (n-1) % 4; minus = -1;
    int n2 = n;
    while (k--) {
        rep(i, n2-1) {
            data2[i] += data2[i+1] * minus;
            minus *= -1;
        }
        n2--;
        /*
        rep(i, n2) cout << data2[i] << " ";
        cout << endl;
        */
    }

    if (n < 5) {
        cout << (max(data1[0], data2[0]) + MOD) % MOD << endl;
        return 0;
    }

    
    int ans1 = 0;
    k = (n1-1) / 4 + 1;
    ans1 += data1[0] + data1[n1-1];
    Rep(i, n1-1) {
        if (i % 2 == 0) {
            ans1 += data1[i] * k;
        }
    }
    //cout << ans1 << endl;


    int ans2 = 0;
    k = (n2-1) / 4 + 1;
    ans2 -= data2[0] + data2[n2-1];
    Rep(i, n2-1) {
        if (i % 2 == 0) {
            ans2 -= data2[i] * k;
        }
    }

    //cout << ans2 << endl;
    cout << (max(ans1, ans2) + MOD ) % MOD << endl;


    return 0;
}

