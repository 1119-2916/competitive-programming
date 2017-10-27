#include<iostream>
#include<cmath>
using namespace std;
#define eps 0.0000000001
 
bool eq(double a,double b){
  return ( -eps < a-b && a-b < eps );
}
 
int N;
int t[256];
 
double calc(int S,int A,int C){
  int cnt[256]={};
  int x=S;
  for(int i=0;i<N;i++){
    x=(A*x+C)%256;
    cnt[(t[i]+x)%256]++;
  }
  double res=0;
  for(int i=0;i<256;i++){
    double d=(double)cnt[i]/(double)N;
    if(eq(d,0))continue;
    res-= d*log(d);
  }
  return res;
}
 
int main(){
 
  while(1){
    cin>>N;
    if(N==0)break;
    for(int i=0;i<N;i++)cin>>t[i];
    int s,a,c;
    double ans=(1e10);
    for(int S=0;S<=15;S++){
      for(int A=0;A<=15;A++){
    for(int C=0;C<=15;C++){
      double d=calc(S,A,C);
       
      if(d<ans-eps){
        ans=d;
        s=S;a=A;c=C;
      }
    }
      }
    }
 
    cout<<s<<' '<<a<<' '<<c<<endl;
  }
  return 0;
}
