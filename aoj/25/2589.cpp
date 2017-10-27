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

int gcd(int a, int b);

int main()
{
    char input[1024];
    while (cin >> input, input[0] != '#') {
        int top = 0, bot = 1, ptr = 0, n = 0;
        vector<bool> dir;
        if (strcmp(input, "north") == 0) {
            cout << 0 << endl;
        } else if (strcmp(input, "west") == 0) {
            cout << 90 << endl;
        } else {
            while (ptr + 3 < strlen(input)) {
                if (strncmp(&input[ptr], "north", 5) == 0) {
                    ptr += 5;
                    dir.pb(true);
                    n++;
                } else if (strncmp(&input[ptr], "west", 4) == 0) {
                    ptr += 4;
                    dir.pb(false);
                    n++;
                }
            }
            if (!dir[n-1]) {
                top = 90;
            }
            for (int i = n-2; i >= 0; i--) {
                if (dir[i]) {
                    top *= 2;
                    bot *= 2;
                    top -= 90;
                } else {
                    top *= 2;
                    bot *= 2;
                    top += 90;
                }
            }
            int g = gcd(top, bot);
            top /= g;
            bot /= g;
            if (bot == 1) {
                cout << top << endl;
            } else {
                cout << top << "/" << bot << endl;
            }
        }
    }
    return 0;
}

int gcd(int a, int b)
{
    if (a == 0 || b == 0) {
        return 1;
    } else {
        while (a != b) {
            if (a < b) {
                b -= a;
            } else {
                a -= b;
            }
        }
        return a;
    }
}

