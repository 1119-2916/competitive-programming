#include<bits/stdc++.h>
using namespace std;
int ans;
int n;
int k;
int s;
void f(int i,int t,int sum){
  if(i==k){
    ans+=(sum==s);
    return;
  }
  for(int j=t;j<=n;j++){
    //    sum+=j;
    f(i+1,j+1,sum+j);
  }
}

int main(){
  while(1){
    cin>>n>>k>>s;
    if(!n)break;
    ans=0;
    f(0,1,0);
    cout<<ans<<endl;
  }
  return 0;
}

  
