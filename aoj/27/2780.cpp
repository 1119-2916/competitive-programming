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

using namespace std;

#define INF 1010001000
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef pair<int, int> i_i;
typedef long long int llong;
typedef pair<llong, llong> ll_ll;
typedef struct edge {int f, t;}Edge;

bool ok(int n);

int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    rep(i, n) {
        cin >> num[i];
    }
    int ret = -1;
    rep(i, n) {
        for (int j = i + 1; j < n; j++) {
            int tmp = num[i] * num[j];
            if (ok(tmp)) {
                ret = max(ret, tmp);
            }
        }
    }
    cout << ret << endl;
    return 0;
}

bool ok(int n)
{
    string a = to_string(n);
    for (int i = 1; i < a.length(); i++) {
        if (a[i-1] + 1 != a[i]) {
            return false;
        }
    }
    return true;
}

