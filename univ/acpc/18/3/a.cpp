#include <bits/stdc++.h>

using namespace std;


bool calc(string st, int a, int b)
{
    int num = 0;
    if (b - a < 1) {
        return false;
    }
    if (b - a == 1 && st[a] == '0') {
        return true;
    } else if (st[a] == '0') {
        return false;
    }
    for (int i = a; i < b; i++) {
        num *= 10; num += st[i] - '0';
    }
    return (num <= 255);
}

int main()
{
    string st;
    cin >> st;

    int ans = 0;
    for (int i = 1; i < st.size(); i++) {
        for (int j = i + 1; j < st.size(); j++) {
            for (int k = j + 1; k < st.size(); k++) {
                if (calc(st, 0, i) && 
                        calc(st, i, j) &&
                        calc(st, j, k) &&
                        calc(st, k, st.size())) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

