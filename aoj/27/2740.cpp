#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
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


int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> at(200, 0), bt(200, 0);
    int pos = 1;
    bool state = false;
    rep(i, a.length()) {
        if (a[i] == '(' && !state) {
            pos *= 2;
        } else if (a[i] == '(' && state) {
            pos = pos * 2 + 1;
        } else if (a[i] == ')') {
            pos /= 2;
        } else if (a[i] == '[') {
            at[pos] = a[++i] - '0';
            cout << at[pos] << " " << pos << endl;
            i++; i++;
            state = !state;
        }
    }
    rep(i, 8) {
        cout << at[i] << " ";
        if (i == 1 || i == 2 || i == 4) {
            cout << endl;
        }
    }
    return 0;
}
