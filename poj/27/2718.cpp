#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <sstream>

using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)


signed main()
{
    ios::sync_with_stdio(false);
    int dataset;
    scanf("%d", &dataset);
    getchar();
    while (dataset--) {
        char a;
        vector<int> data;
        while (a = getchar(), a != '\n') {
            if ('0' <= a && a <= '9') {
                data.push_back(a - '0');
            }
        }
        int ans = 2147483647;
        int n = data.size();
        do {

            int len = n/2;
            if (len != 1 && data[0] == 0) continue;
            if (len != 1 && data[len] == 0) continue;

            int a = 0, b = 0;
            rep(i, len) {
                a *= 10;
                a += data[i];
            }
            for (int i = len; i < n; i++) {
                b *= 10;
                b += data[i];
            }

            int ret = abs(a - b);
            if (ans > ret) {
                ans = ret;
            }
        } while (next_permutation(data.begin(), data.end()));
        cout << ans << endl;
    }

    return 0;
}

