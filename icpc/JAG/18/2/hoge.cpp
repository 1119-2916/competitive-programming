#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(void)
{
    map<string, string> funami;
    funami["abcabc"] = "abc";

    if (funami["aabc"] == "") {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}


