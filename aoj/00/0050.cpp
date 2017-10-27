#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
using namespace std;

int main()
{
    string s, a = "apple", p = "peach";
    getline(cin, s);
    for (int i = 0; i < s.length()-4; i++) {
        string sub = s.substr(i, 5);
        if (sub == a) {
            for (int j = 0; j < 5; j++) {
                s[i+j] = p[j];
            }
        } else if (sub == p) {
            for (int j = 0; j < 5; j++) {
                s[i+j] = a[j];
            }
        }
    }
    cout << s << endl;
    return 0;
}
        
