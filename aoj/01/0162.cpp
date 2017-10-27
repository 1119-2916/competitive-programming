#include <iostream>
#include <algorithm>

using namespace std;

bool prime[1000001];
int ans[1000001];

void erat()
{

    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < 1000001; i++) {
        prime[i] = true;
    }

    for (int i = 2; i < 500001; i++) {
        if (prime[i]) {
            for (int j = 2; j*i < 1000001; j++) {
                prime[i*j] = false;
            }
        }
    }
}

void solve()
{
    ans[0] = 0;
    for (int i = 1; i < 1000001; i++) {
        ans[i] = 1;
    }
    for (int i = 7; i < 1000001; i++) {
        if (prime[i]) {
            for (int j = 2; i*j < 1000001; j++) {
                ans[i*j] = 0;
            }
            ans[i] = 0;
        }
    }
    for (int i = 1; i < 1000001; i++) {
        ans[i] += ans[i-1];
    }
}

int main() 
{
    int m, n;
    cin >> m;

    erat();
    solve();

    while (m) {
        cin >> n;
        cout << ans[n] - ans[m-1] << endl;
        cin >> m;
    }
    return 0;
}

