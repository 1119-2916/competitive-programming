#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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

vector<bool> num(21, false);

int search(int n, int k, int s);

int main()
{
    int n, k, s;
    while (cin >> n >> k >> s, k) {
        cout << search(n, k, s) << endl;
    }
    return 0;
}

int search(int n, int k, int s)
{
    int ret = 0;
    if (k > 1) {
        for (int i = n; i > 0; i--) {
            if (i < s) {
                ret += search(i-1, k-1, s-i);
            }
        }
    } else {
        if (0 <= s && s <= n) {
            return 1;
        } else {
            return 0;
        }
    }
    return ret;
}





