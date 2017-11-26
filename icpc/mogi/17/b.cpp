#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>

string input;
int ptr;
vi cnt;

char solve()
{
    if (input[ptr] == '[') {
        //cout << input[ptr];
        ptr++;
        char left = solve();
        //cout << input[ptr];
        ptr++;
        char right = solve();
        //cout << input[ptr];
        ptr++;
        if (cnt[left] < cnt[right]) {
            cnt[right]--;
            return right;
        } else {
            cnt[left]--;
            return left;
        }
    } else {
        //cout << input[ptr];
        return input[ptr++] - 'a';
    }
}

signed main()
{
    cin >> input;

    char a; int b;
    cnt = vi('z'-'a'+1, 0);
    while (scanf("%c %lld", &a, &b) != EOF) {
        cnt[a - 'a'] = b;
    }

    ptr = 0;
    solve();

    for (int i = 0; i < 'z' - 'a' + 1; i++) {
        if (cnt[i] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}

