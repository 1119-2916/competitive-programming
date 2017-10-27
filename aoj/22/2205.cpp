#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

typedef pair<string, int> s_i;

bool gj(string a, string b);

int n, m;

int main()
{
    while (cin >> n >> m, n) {
        long long int ans = 0;
        vector<s_i > cls(n);
        for (int i = 0; i < n; i++) {
            string s;
            int a;
            cin >> s >> a;
            cls[i].first = s; cls[i].second = a;
        }
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                if (gj(s, cls[j].first)) {
                    ans += cls[j].second;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

bool gj(string a, string b)
{
    for (int i = 0; i < 8; i++) {
        if (!(a[i] == b[i] || b[i] == '*')) {
            return false;
        }
    }
    return true;
}



