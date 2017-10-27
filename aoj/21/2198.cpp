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
    int n;
    while (cin >> n, n) {
        vector<pair<double, string> > input(n);
        rep(i, n) {
            cin >> input[i].second;
            int price, a, b, c, d, e, seed, sell, num;
            cin >> price >> a >> b >> c >> d >> e >> seed
                >> sell >> num;
            double time = a + b + c + (d + e) * num;
            double income = seed * sell * num - price;
            input[i].first = -income / time;
        }
        sort(input.begin(), input.end());
        rep(i, n) {
            cout << input[i].second << endl;
        }
        cout << "#" << endl;
    }
    return 0;
}
