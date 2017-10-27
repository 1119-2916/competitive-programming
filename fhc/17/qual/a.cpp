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
    rep(i, n) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i+1 << ": ";
        if ( (50 - b) * (50 - b) + (50 - c) * (50 - c) > 50 * 50) {
            cout << "white" << endl;
        } else {
            double comp = cos((double)(36*a*0.1))*cos((double)(36*a*0.1));
            if (b < 50) {




    return 0;
}
