#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int n, m;

    cin >> n;
    cin >> m;
    vector<int> ami(n, 0);

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        ami[a]++;
        ami[a-1] = max(ami[a-1], ami[a]);
        ami[a+1] = max(ami[a], ami[a+1]);
        //cout << "up :" << a << ami[a] << endl;
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, ami[i]);
        //cout << ami[i] << " ";
    }
    //puts("");
    cout << ans << endl;

    return 0;
}

