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

vector<bool> prime(1299710, true);
int n = 1299710;


int main()
{
    sieve();
    int a;
    while (cin >> a, a) {
        int bef, aft, ptr = a;
        while (1) {
            if (prime[ptr]) {
                bef = ptr;
                break;
            } else {
                ptr--;
            }
        }
        ptr = a;
        while (1) {
            if (prime[ptr]) {
                aft = ptr;
                break;
            } else {
                ptr++;
            }
        }
        cout << aft - bef << endl;
    }
    return 0;
}


void sieve()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = 2; j * i < n; j++) {
                prime[i*j] = false;
            }
        }
    }
}


