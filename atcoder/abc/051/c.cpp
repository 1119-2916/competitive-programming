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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    rep(i, c-a) {
        cout << "R";
    }
    rep(i, d-b) {
        cout << "U";
    }
    rep(i, c-a) {
        cout << "L";
    }
    rep(i, d-b) {
        cout << "D";
    }

    cout << "D";

    rep(i, c-a+1) {
        cout << "R";
    }
    rep(i, d-b+1) {
        cout << "U";
    }

    cout << "LU";

    rep(i, c-a+1) {
        cout << "L";
    }
    rep(i, d-b+1) {
        cout << "D";
    }
    cout << "R" << endl;
    return 0;
}
