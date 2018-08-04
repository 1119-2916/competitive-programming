#include<bits/stdc++.h>
using namespace std;

#define P pair<char,int>
#define fir first
#define sec second
#define PA pair<int,int>


void f(int n,int l){
    P a[10000]={};
    queue<PA> q;

    for(int i=0;i<n;i++){
        char d;
        int p;
        cin>>d>>p;
        a[i].fir=d;
        a[i].sec=p;
    }
    int sum=0,last=0,time=0,latime=0;
    while(sum<n){
        for(int i=0;i<n;i++){
            if(a[i].fir=='R') a[i].sec++;
            if(a[i].fir=='L') a[i].sec--;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i].fir=='L'&&a[j].fir=='R'&&
                        a[i].sec==a[j].sec){
                    a[i].fir='R';
                    a[j].fir='L';
                }
            }
        }
        for(int i=0;i<n;i++){
            if(a[i].sec==0||a[i].sec==l){
                sum++;
                if(n==sum&&latime==time&&a[i].sec==l) continue;
                last = i+1;
                latime=time;
            }
        }
        time++;
    }

    cout<<time<<' '<<last<<endl;
}



signed main(){
    int n,l;
    while(1){
        cin>>n>>l;
        if(!n) break;
        f(n,l);
    }
}
