#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>

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
    int n, m;
    while (cin >> n >> m, (n|m)) {
        int ans = INF, ret;
        rep(i, n) {
            if (ans > abs((i+1)*(i+1)+(n-i-1)*(n-i-1)-m*m)) {
                ans = abs((i+1)*(i+1)+(n-i-1)*(n-i-1)-m*m);
                ret = i;
            }
        }
        int i = ret;
        cout << abs(sqrt((i+1)*(i+1)+(n-i-1)*(n-i-1))-m) << endl;
    }
    return 0;
}
