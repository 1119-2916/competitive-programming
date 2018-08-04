#include <bits/stdc++.h>
using namespace std;
int n,m,ans=10000000;
int b[10000];
int p[1000];


void f(int t[]){
    int res=0;
    int s[1000]={};
    for(int i=0;i<n;i++){
        s[i]=t[i];
    }

    for(int i=0;i<n;i++){
        int j=i;

        while(j<n && b[i]!=s[j]){
           j++;
        }
        if(j==n) return;
        for(int k=j;k>i;k--){
            int c = s[k];
            s[k] = s[k-1];
            s[k-1] = c;
            res++;
        }
   }

    ans = min(ans,res);
}


signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        b[i] = c;
    }
    for(int i=0;i<m;i++){
        cin>>p[i];
    }

    int t[1000]={};
    int sum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<p[i];j++){
            if(i%2)
                t[sum+j]=1;
            else
                t[sum+j]=0;
        }
        sum+=p[i];
    }

    f(t);
    for(int i=0;i<n;i++){
        if(t[i]==1) t[i]=0;
        else t[i]=1;
    }
    f(t);

    cout<<ans<<endl;

}

