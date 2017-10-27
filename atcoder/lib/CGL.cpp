#include<bits/stdc++.h>
using namespace std;

typedef complex<double> P;
double eps=1e-8;
bool eq(double a,double b){return (b-a<eps&&a-b<eps);}
double cross(P a,P b){return real(b*conj(a));}
double dot(P a,P b){return imag(b*conj(a));}
P project(P a,P b,P c){b-=a;c-=a;return a+b*real(c/b);}
P reflect(P a,P b,P c){b-=a;c-=a;return a+conj(c/b)*b;}
int ccw(P a,P b,P c){
  b-=a,c-=a,a=c*conj(b);
  if(a.imag()>eps)return 1;//ccw
  if(a.imag()<-eps)return -1;//cw
  if(a.real()<-eps)return 2;//ob
  if(abs(b)+eps<abs(c))return -2;//of
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
 
int main(){
  int T;
  cin>>T;
  while(T--){
    double ax,ay,bx,by,cx,cy,dx,dy;
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
     
    cout<< isintersect ( P(ax,ay) , P(bx,by) , P(cx,cy) , P(dx,dy) ) <<endl;
  //    printf("%.12f\n",dist( P(ax,ay) , P(bx,by) , P(cx,cy) , P(dx,dy) ) );
  }
}
