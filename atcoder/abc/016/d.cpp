#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-7
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back

typedef complex<double> P;
typedef pair<int, int> i_i;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<bool> vb;
typedef vector<vb > vvb;
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

bool eq(double a,double b){return (b-a<EPS&&a-b<EPS);}
double cross(P a,P b){return real(b*conj(a));}
double dot(P a,P b){return imag(b*conj(a));}
P project(P a,P b,P c){b-=a;c-=a;return a+b*real(c/b);}
P reflect(P a,P b,P c){b-=a;c-=a;return a+conj(c/b)*b;}
int ccw(P a,P b,P c){
  b-=a,c-=a,a=c*conj(b);
  if(a.imag()>EPS)return 1;//ccw
  if(a.imag()<-EPS)return -1;//cw
  if(a.real()<-EPS)return 2;//ob
  if(abs(b)+EPS<abs(c))return -2;//of
  return 0;//os
}
 
//segment ab , point c
double dist(P a,P b,P c){
  if(dot(b-a,c-a)<0)return abs(c-a);
  if(dot(a-b,c-b)<0)return abs(c-b);
  return imag((c-a)*conj(b-a))/abs(b-a);
}
 
bool isintersect(P a,P b,P c,P d){
  return ((ccw(a,b,c)*ccw(a,b,d)<=0)&&(ccw(c,d,a)*ccw(c,d,b)<=0));
}
 
//segment ab , segment cd
P intersect(P a,P b,P c,P d){
  a-=d;b-=d;c-=d;
  return d+a+(b-a)*imag(a/c)/imag(a/c-b/c);
}
 
double dist(P a,P b,P c,P d){
  if(isintersect(a,b,c,d))return 0;
  return min(min(abs(a-c),abs(a-d)),min(abs(b-c),abs(b-d)));
}


signed main()
{
    double e, f, c, d;
    cin >> e >> f >> c >> d;
    P a(e +1000.0, f +1000.0), b(c +1000.0, d +1000.0);
    int n;
    cin >> n;
    vector<P> plg(n);
    rep(i, n) {
        cin >> plg[i].real() >> plg[i].imag();
        plg[i].real() += 1000;
        plg[i].imag() += 1000;
    }
    int cnt = 0;
    Rep(i, n) {
        cnt += isintersect(a, b, plg[i-1], plg[i]);
    }
    cnt += isintersect(a, b, plg[n-1], plg[0]);

    cout << cnt / 2 + 1 << endl;

    return 0;
}
