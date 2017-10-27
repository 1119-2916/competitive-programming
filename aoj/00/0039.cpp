#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    string n;
    int mp[127], i;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    while (cin >> n) {
        int ans = 0;
        for (i = 0; i < n.length()-1; i++) {
            if (mp[n[i+1]] <= mp[n[i]]) {
                ans += mp[n[i]];
            } else {
                ans -= mp[n[i]];
            }
        }
        ans += mp[n[i]];
        cout << ans << endl;
    }
    return 0;
}
