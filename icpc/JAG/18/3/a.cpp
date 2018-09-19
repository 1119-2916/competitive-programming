#include<bits/stdc++.h>
using namespace std;

string s;


int main(){
    cin>>s;
    int dir=0;
    int ans=0;

    for(int i=0;i<(int)s.size();i++){
        if(dir==0&&s[i]=='R'){
            dir++;
        
            bool flag[5]={};
            flag[0]=true;
            flag[1]=true;

            while(dir%4!=0&&i!=s.size()){
                i++;
                if(s[i]=='L') dir--;
                if(s[i]=='R') dir++;
                if(s[i]=='R') flag[dir]=true;
            }

            if(dir%4==0&&flag[0]&&flag[1]&&flag[2]&&flag[3]&&flag[4]){
        
                ans++;
            }
        }
        else{
            if(s[i]=='R') dir++;
            if(s[i]=='L') dir--;
        }
        dir = (dir+4)%4;
    }

    cout<<ans<<endl;
}
