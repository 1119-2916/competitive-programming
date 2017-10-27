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


int main()
{
    int n;
    cin >> n;
    string st;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        st.pb(tmp + '0');
    }
    rep(i, 101010) {
        string ser = to_string(i);
        if (st.find(ser) == string::npos) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
