#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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

int main()
{
    int t;
    cin >> t;
    rep(i, t) {
        cout << "Case #" << i+1 << ": ";
        int n;
        cin >> n;
        vector<int> item(n);
        rep(j, n) {
            cin >> item[j];
        }
        sort(item.begin(), item.end(), greater<int>());

        int ret = 0, end = n;
        for (int j = 0; j < end; j++) {
            int res = 50 - item[j];
            if (res <= 0) {
                ret++;
                continue;
            } else {
                end -= res / item[j];
                end -= (res % item[j])?1:0;
                if (end > j) {
                    ret++;
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}
