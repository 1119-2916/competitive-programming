#include <bits/stdc++.h>
 
using namespace std;

#define int long long 

bool calc(int a);

string s;

signed main()
{
    cin >> s;
    for (int i = 2001; i >= 1; i--) {
        if (calc(i)) {
            cout << "(x-" << i << ")";
        }
    }
    for (int i = -1; i >= -2000; i--) {
        if (calc(i)) {
            cout << "(x+" << -i << ")";
        }
    }
    cout << endl;
    return 0;
}

bool calc(int a)
{
    //cout << a << endl;;
    int ptr = 0, sum = 0, num = 1;
    while (s.size() > ptr) {
        //cout << s[ptr] << endl;
        if (s[ptr] == 'x') {
            if (ptr+1 < s.size() && s[ptr+1] == '^') {
                sum += num * (int)pow(a, s[ptr+2] - '0');
                ptr += 3;
            } else {
                sum += num * a;
                ptr++;
            }
        } else if (s[ptr] == '+') {
            num = 1;
            ptr++;
        } else if (s[ptr] == '-') {
            num = -1;
            ptr++;
        } else if ('0' <= s[ptr] && s[ptr] <= '9') {
            int minus = (num < 0) ? -1 : 1;
            num = s[ptr++] - '0';
            while (ptr < s.size() && '0' <= s[ptr] && s[ptr] <= '9') {
                num *= 10;
                num += s[ptr++] - '0';
            }
            num *= minus;
        } else {
            //cout << "error " <<  ptr << endl;
            //return false;
        }
        //cout << num << " " << sum << endl;
    }
    //cout << sum << endl;
    sum += num;
    //cout << sum << endl;
    if (sum) return false; 
    else return true;
}

