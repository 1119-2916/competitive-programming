#include<bits/stdc++.h>
using namespace std;


void f(int x,int y){
    int a[100];

    for(int i=0;i<x;i++){
        cin>>a[i];
    }
    int n=0,m=0;

    for(int i=0;i<y;i++){
        int b;
        cin>>b;
        bool flag=false;
        for(int j=0;j<x;j++){
            if(a[j]==b)
                flag = true;
        }
        if(flag){
            m++;
        }
        else{
            n++;
        }
    }
    n+=x;
    

    if(n<m*2){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}



    

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        f(a,b);
    }
}

