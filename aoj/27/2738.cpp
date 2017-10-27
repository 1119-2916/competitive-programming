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


int main()
{
    int n, a = 0;
    cin >> n;
    rep(i, n) {
        string aun;
        cin >> aun;
        if (aun[0] == 'A') {
            a++;
        } else {
            a--;
            if (a < 0) {
                puts("NO");
                return 0;
            }
        }
    }
    if (a) {
        puts("NO");
    } else {
        puts("YES");
    }




    return 0;
}
