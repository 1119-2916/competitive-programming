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

void sieve();

vector<bool> prime(300001, true);

int main()
{
    int n;
    sieve();
    while (cin >> n, n != 1) {
        cout << n << ":";
        for (int i = 2; i <= n; i++) {
            if (prime[i] && !(n % i)) {
                cout << " " << i;
            }
        }
        cout << endl;
    }
    return 0;
}

void sieve()
{
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < 300001; i++) {
        if (prime[i]) {
            if (i % 7 == 1 || i % 7 == 6) {
                for (int j = 2; j * i < 300001; j++) {
                    prime[i*j] = false;
                }
            } else {
                prime[i] = false;
            }
        }
    }
}



