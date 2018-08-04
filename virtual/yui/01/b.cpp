#include <bits/stdc++.h>
using namespace std;

signed main(){
  string s;
  int ans;
  cin>>s>>ans;
  int a[10];
  int pos=0;
  a[0]=s[0]-'0';
  for(int i=1;i<s.length();i+=2){
    if(s[i]=='+'){
      a[++pos]=s[i+1]-'0';
    }else{
      int t=a[pos];
      a[pos]=t*(s[i+1]-'0');
    }
  }
  int sa=0;
  for(int i=0;i<=pos;i++){
    sa+=a[i];
  }
  int sb=s[0]-'0';
  for(int i=1;i<s.length();i+=2){
    if(s[i]=='+'){
      sb+=(s[i+1]-'0');
    }else{
      sb*=(s[i+1]-'0');
    }
  }
  if(ans==sa&&ans==sb)
    cout<<'U'<<endl;
  else if(ans==sa)
    cout<<'M'<<endl;
  else if(ans==sb)
    cout<<'L'<<endl;
  else
    cout<<'I'<<endl;
}
