#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
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
    int n;
    while (cin >> n, n) {
        vector<int> vote(26, 0);
        bool fl = false;
        rep(i, n) {
            string s;
            cin >> s;
            vote[s[0]-'A']++;

            if (!fl) {
                int fir = -1, sec = -1;
                rep(j, 26) {
                    if (vote[fir] < vote[j]) {
                        sec = fir;
                        fir = j;
                    } else if (vote[sec] < vote[j]) {
                        sec = j;
                    }
                }
                if (vote[fir] - vote[sec] > n - i - 1) {
                    putchar(fir + 'A');
                    cout << " " << i+1 << endl;
                    fl = true;
                }
            }
        }
        if (!fl) {
            cout << "TIE" << endl;
        }
    }
    return 0;
}
