#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++) 

int main()
{
    int n;
    cin >> n;

    rep(llllll, n) {
        string str;
        cin >> str;
        rep(i, str.length()) {
            int cnt = 0;
            char com;
            if (str[i] == '0') {
                out(com, cnt);
                cnt = 0;
                com = '0';
            } else {
                com = str[i];
                cnt++;
            }
        }
    }

    return 0;
}

void out(char com, int cnt)
{
    if (com == '0') {
        return ;
    }
    switch(com) {
        case '1' :
            switch(cnt%







