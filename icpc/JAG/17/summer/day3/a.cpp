#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            st.pop();
        }else{
            cout<<st.size()<<endl;
            break;
        }
    }
    return 0;
}
