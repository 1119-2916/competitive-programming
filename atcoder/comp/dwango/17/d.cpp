#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define INF 1010001000
#define MAX 100001
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef pair<int, int> i_i;

vector<i_i > sushi(MAX);
vector<i_i > diff(MAX);
vector<bool> check(MAX, false);

int main()
{
    int n, m;
    long long int ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> sushi[i].first >> sushi[i].second;
        diff[i].first = sushi[i].first - sushi[i].second;
        diff[i].second = i;
    }

    sort(&diff[0], &diff[n], greater<i_i >());

    for (int i = 0; i < m-1; i++) {
        check[diff[i].second] = true;
    }

    int br = 0, end = n;
    for (int i = 0; i < n; i++) {
        if (check[i]) {
            ans += sushi[i].first;
            br++;
        } else {
            ans += sushi[i].second;
        }
        if (br == m-1) {
            end = i;
            break;
        }
    }

    long long int ret = ans, add = 0;

    for (int i = 0; i < n; i++) {
        if (i <= end) { 
            if (!check[i]) {
                ret = max(ret, ans + sushi[i].first - sushi[i].second);
            }
        } else {
            ret = max(ans + add + sushi[i].first, ret);
            add += sushi[i].second;
        }
    }

    cout << ret << endl;

    return 0;
}
