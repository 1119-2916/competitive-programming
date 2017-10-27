#include<iostream>
#include<algorithm>
#include <string>
#include<cstdio>
#include<stack>
#include<cstring>
#include<vector>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define D(n,retu) REP(i,n){cin>>retu[i];}

using namespace std;
typedef long long ll;
template<typename T>
void fill_all(T& arr, const T& v) {
    arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
    for (auto& i : arr) { fill_all(i, v); }
}

//------------------変数-----------------------//
ll n, k, a[300005], goukei = 0;
//-------------------関数----------------------//

int main() {
    cin >> n >> k;
    REP(i, n) { cin >> a[i]; }
    sort(a, a + n);
    if (a[n - 1] < k) { cout << "IMPOSSIBLE" << endl; return 0; }
    ll fir = a[0];
    ll yaku = 1173878142377241;
    ll cou = 1;
    REP(i, n - 1) {
        yaku = min(yaku, a[i + 1] - a[i]);
    }
    REP(i, n) {
        if (a[i] % yaku == 0) {

        }
        else { cout << "POSSIBLE" << endl; return 0; }
    }

    if (k%yaku == 0) { cout << "POSSIBLE" << endl; return 0; }

    cout << "IMPOSSIBLE" << endl; return 0;
}
