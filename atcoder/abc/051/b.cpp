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
    int k, s;
    cin >> k >> s;
    llong ret = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = i; j <= k; j++) {
            for (int l = j; l <= k; l++) {
                if (i + j + l == s) {
                    if (i == j && j == l) {
                        ret++;
                    } else if (i == j || j == l || i == l) {
                        ret += 3;
                    } else {
                        ret += 6;
                    }
                }
            }
        }
    }
    cout << ret << endl;


    return 0;
}
