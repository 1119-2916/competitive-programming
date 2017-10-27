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

vector<bool> prime(111000, true);

void sieve();


int main()
{
    int n, m;
    sieve();
    while (cin >> n >> m, n != -1) {
        int cnt = 0;
        vector<int> ans;
        for (int i = n+1; cnt < 100; i++) {
            if (prime[i]) {
                int ct = 0;
                for (int j = i; ct < 100; j++) {
                    if (prime[j]) {
                        ans.push_back(i+j);
                        ct++;
                    }
                }
                cnt++;
            }
        }
        sort(ans.begin(), ans.end());

        cout << ans[m-1] << endl;
    }

    return 0;
}


void sieve()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < 111000; i++) {
        if (prime[i]) {
            for (int j = 2; i * j < 111000; j++) {
                prime[i*j] = false;
            }
        }
    }
}

