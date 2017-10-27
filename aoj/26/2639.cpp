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
    int a, b, c;
    cin >> a >> b >> c;
    int time = c;
    rep(i, 101000) {
        if (a * i + b * i <= time && time <= a * (i + 1) + b * i) {
            cout << time << endl;
            return 0;
        } else if (time < a * i + b * i) {
            time += 60;
            i--;
        }
    }
    cout << -1 << endl;

    return 0;
}
