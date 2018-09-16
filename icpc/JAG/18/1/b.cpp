#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin>>T;
  for(int q=0;q<T;q++){
    vector<int> c(6);
    for(int i=0;i<6;i++)cin>>c[i];
    vector<int> a(14);
    for(int i=0;i<6;i++)a[c[i]]++;
    vector<int> num(5);
    for(int i=0;i<13;i++)num[a[i+1]]++;
    if(num[3]==1&&num[2]==1)cout<<"full house"<<endl;
    else if(num[4]==1&&num[2]==1)cout<<"tiki pair"<<endl;
    else if(num[4]==1)cout<<"tiki"<<endl;
    else if(num[3]==2)cout<<"two triples"<<endl;
    else if(num[3]==1)cout<<"one triple"<<endl;
    else if(num[2]==3)cout<<"three pairs"<<endl;
    else if(num[2]==2)cout<<"two pairs"<<endl;
    else if(num[2]==1)cout<<"one pair"<<endl;
    else cout<<"single"<<endl;
  }
}
