#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N,K,sum=0,res=0;
    cin>>N>>K;
    int a[N];
    rep(i,N)cin>>a[i];
    sort(a,a+N,greater<int>());
    rep(i,N)if((sum+=a[i])>=K){
        res = i+1;
        sum -= a[i];
    }
    cout<<N-res<<endl;
    return 0;
}
