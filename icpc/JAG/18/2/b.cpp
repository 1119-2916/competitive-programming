#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < n; i++) 

int n;
int ans;

void f(int k,int a,int m){
  if(m<0)return;
  if(m==0){
    ans++;
    return;
  }
  if(k==5){
    if(m>0){
      ans++;
    }
    return;
  }
  if(a==5){
    rep(i,5){
      f(k+1,2,m-i);
    }
  }
  else{
    rep(i,2){
      f(k+1,5,m-i);
    }
  }
}

signed main(void)
{
  cin>>n;
  if(n>=14){
    cout<<500<<endl;
    return 0;
  }

  f(0,5,n);
  cout<<ans<<endl;
  return 0;
}


