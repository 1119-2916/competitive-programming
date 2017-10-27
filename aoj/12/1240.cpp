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

void J();
void C();
void E();
void A();
void P();
void M();

int n, len;
string data;

int main()
{
    cin >> n;
    rep(state, n) {
        string change;
        cin >> change >> data;
        len = data.length();
        for (int i = change.length()-1; i >= 0; i--) {
            if (change[i] == 'J') {
                J();
            } else if (change[i] == 'C') {
                C();
            } else if (change[i] == 'E') {
                E();
            } else if (change[i] == 'A') {
                A();
            } else if (change[i] == 'P') {
                P();
            } else if (change[i] == 'M') {
                M();
            }
        }
        cout << data << endl;
    }
    return 0;
}

void C()
{
    char tmp = data[0];
    rep(i, len-1) {
        data[i] = data[i+1];
    }
    data[len-1] = tmp;
}

void J()
{
    char tmp = data[len-1];
    for (int i = len - 1; i > 0; i--) {
        data[i] = data[i-1];
    }
    data[0] = tmp;
}

void E()
{
    int odd = len % 2;
    for (int i = 0; i < len/2; i++) {
        char tmp = data[i];
        data[i] = data[i + len / 2 + odd];
        data[i + len / 2 + odd] = tmp;
    }
}

void A()
{
    reverse(data.begin(), data.end());
}

void M()
{
    rep(i, len) {
        if (data[i] == '9') {
            data[i] = '0';
        } else if ('0' <= data[i] && data[i] < '9') {
            data[i]++;
        } 
    }
}

void P()
{
    rep(i, len) {
        if (data[i] == '0') {
            data[i] = '9';
        } else if ('0' < data[i] && data[i] <= '9') {
            data[i]--;
        } 
    }
}

