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

void skip(int p, int s);
void decrement(int p);

int n;
string st;

int main()
{
    while (cin >> n, n) {
        vector<int> data(n);
        rep(i, n) {
            cin >> data[i];
        }
        cin >> st;
        for (int i = 0, j = 0; i < st.length(); i++, j++) {
            if (j == n) {
                j = 0;
            }
            skip(i, data[j]);
        }
        cout << st << endl;
    }
    return 0;
}

void skip(int p, int s)
{
    rep(i, s) {
        decrement(p);
    }
}

void decrement(int p)
{
    if (st[p] == 'A') {
        st[p] = 'z';
    } else if (st[p] == 'a') {
        st[p] = 'Z';
    } else {
        st[p]--;
    }
}
