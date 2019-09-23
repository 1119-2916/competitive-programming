#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define double long double


#define ll long long
using box = vector<ll>;


ll check(ll v1, box& q, box& x, box& s, box& t)
{
    int Q = q.size();
    ll v = v1;
    rep(i, Q)
    {
        if(q[i] == 1)
        {
            if(v >= x[i])
            {
                v = t[i] * (v + s[i]);
            }
        }
        else
        {
            if(v <= x[i])
            {
                v = (v - s[i]) / t[i]; 
            }
        }
        //cout << v << endl;
    }
    return v;
}
void solve()
{
    ll N, Q, L, R;
    cin >> N >> Q >> L >> R;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> q(Q);
    vector<ll> x(Q);
    vector<ll> s(Q);
    vector<ll> t(Q);
    rep(i, Q)
    {
        cin >> q[i] >> x[i] >> s[i] >> t[i];
    }
    //L以上となる最初の頂点
    int ok = N;
    int ng = -1;
    while(abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;
        if(check(A[mid], q, x, s, t) >= L)
        {
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    //cout << ok << " " << ng << endl;

    //R以下となる最大の頂点
    int rok = -1;
    int rng = N;
    while(abs(rok - rng) > 1)
    {
        int mid = (rok + rng) / 2;
        if(check(A[mid], q, x, s, t) <= R)
        {
            rok = mid;
        }
        else{
            rng = mid;
        }
    }
    //cout << rok << " " << rng << endl;

    cout << (max(rok - ok + 1, 0)) << endl;

    // rep(i, N){
    //     cout << A[i] << " " << (check(A[i], q, x, s, t)) << endl;
    // }

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
