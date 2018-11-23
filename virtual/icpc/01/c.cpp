#include<bits/stdc++.h>
using namespace std;



bool f(){
    int p,q;
    cin>>p>>q;
    int s = p*p+q*q;

    for(int i=1;i*i<=s;i++){
        if(s%i==0){
            for(int j=0;j*j<=i;j++){
                int x = j;
                int y = sqrt(i-j*j);
                if(y!=sqrt(i-j*j))
                    continue;

                int t = s/i;
                for(int k=0;k*k<=t;k++){
                    int m = k;
                    int n = sqrt(t-k*k);
                    if(n!=sqrt(t-k*k))
                        continue;

                    for(int a=-1;a<2;a+=2){
                        for(int b=-1;b<2;b+=2){
                            for(int c=-1;c<2;c+=2){
                                for(int d=-1;d<2;d+=2){
                                    if(a*m*c*x-b*n*d*y==p&&a*m*d*y+b*n*c*x==q){
                                        if(!(m==0&&n==1)&&!(m==1&&n==0)&&!(x==0&&y==1)&&!(x==1&&y==0)){
                                        
                                            return false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}




signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        if(f()){
            cout<<"P"<<endl;
        }
        else{
            cout<<"C"<<endl;
        }
    }
}
