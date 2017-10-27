#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define INF 1010001000

typedef long long int ll;

ll tr(string a);
bool cl(string a);
int c3(ll a);
int solve(string st);

int main()
{
    string input;
    cin >> input;
    while (input[0] != '0') {
        int ans = solve(input);
        if (ans != INF) {
            cout << ans << endl;
        } else {
            cout << "NA" << endl;
        }
        cin >> input;
    }
    return 0;
}

int solve(string st)
{
    int ans = 0;
    vector<bool> check(1048576, false);
    queue<string> a, b, c;
    if ( cl(st) ) {
        return ans;
    }
    a.push(st);
    while (!a.empty()) {
        while (!a.empty()) {
            st = a.front();
            a.pop();
            if (check[c3(tr(st))]) {
                continue;
            } else {
                check[c3(tr(st))] = true;
                //cout << c3(tr(st)) << endl;
            }
            if (cl(st)) {
                return ans;
            }
            for (int i = 1; i < st.size(); i++) {
                if (st[i-1] != st[i]) {
                    string nw(st);
                    if (st[i-1] != 'r' && st[i] != 'r') {
                        nw[i-1] = 'r';
                        nw[i] = 'r';
                    } else if (st[i-1] != 'g' && st[i] != 'g') {
                        nw[i-1] = 'g';
                        nw[i] = 'g';
                    } else if (st[i-1] != 'b' && st[i] != 'b') {
                        nw[i-1] = 'b';
                        nw[i] = 'b';
                    }
                    b.push(nw);
                }
            }
        }
        a = b;
        b = c;
        ans++;
    }
    return INF;
}

ll tr(string a)
{
    ll ret = 0;
    for (int i = 0; i < a.size(); i++) {
        ret *= 10;
        if (a[i] == 'r') {
            ret += 1;
        } else if (a[i] == 'g') {
            ret += 2;
        } else {
            ret += 3;
        }
    }
    return ret;
}

bool cl(string a)
{
    for (int i = 1; i < a.size(); i++) {
        if (a[i-1] != a[i]) {
            return false;
        }
    }
    return true;
}

int c3(ll a)
{
    int ret = 0;
    if (a) {
        ret = c3(a / 10);
        ret *= 4;
        ret += a % 10;
    }
    return ret;
}
