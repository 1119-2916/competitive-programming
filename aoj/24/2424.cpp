#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define INF 1010001000
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef pair<int, int> i_i;
typedef long long int llong;
typedef pair<llong, llong> ll_ll;
typedef struct edge {int f, t;}Edge;

int q;

int main()
{
    cin >> q;
    rep(lp, q) {
        int n, cnt = 0;
        cin >> n;
        char data[20] = "";
        sprintf(data, "%d", n);
        while (strlen(data) != 1 && cnt < 101000) {
            int len = strlen(data), ret = -1;
            for (int i = 1; i < len; i++) {
                int a = atoi(data);
                a /= pow(10, (len - i));
                int b = atoi(&data[i]);
                ret = max(ret, a*b);
            }
            sprintf(data, "%d", ret);
            cnt++;
        }
        if (cnt < 101000) {
            cout << cnt << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
