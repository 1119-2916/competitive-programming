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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define int3(x, y, z) int x, y, z; scanf("%lld %lld %lld", &x, &y, &z);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int3(n, w, h);
    w += w; h += h;
    vi wid(w+w+2, 0), hei(h+h+2, 0);
    rep(i, n) {
        int3(a, b, c);
        a += a; b += b; c += c;
        wid[ ( ( a-c > 0) ? a-c : 0 )] += 1;
        wid[ ( ( a+c+1 < w+1 ) ? a+c+1 : w+1 )] += -1;
        hei[ ( ( b-c > 0) ? b-c : 0 )] += 1;
        hei[ ( ( b+c+1 < h+1 ) ? b+c+1 : h+1 )] += -1;
/*
cout <<  ( ( a-c > 0) ? a-c : 0 ) << endl;
cout <<  ( ( a+c+1 < w+1 ) ? a+c+1 : w+1 ) << endl;
cout <<  ( ( b-c > 0) ? b-c : 0 ) << endl; 
cout <<  ( ( b+c+1 < h+1 ) ? b+c+1 : h+1 ) << endl;
*/
    }
/*
    rep(i, w+1) {cout << wid[i] << " "; } cout << endl;
    rep(i, h+1) {cout << hei[i] << " "; } cout << endl;
  */  

    bool ans = true;
    rep(i, w+1) {
        wid[i+1] += wid[i];
        ans &= wid[i] > 0;
    }
    if ( ans ) {
        cout << "Yes" << endl;
        return 0;
    }
    ans = true;
    rep(i, h+1) {
        hei[i+1] += hei[i];
        ans &= hei[i] > 0;
    }
/*
    rep(i, w+1) {cout << wid[i] << " "; } cout << endl;
    rep(i, h+1) {cout << hei[i] << " "; } cout << endl;
 */  


    cout << ((ans)?"Yes":"No") << endl;
    return 0;
}

