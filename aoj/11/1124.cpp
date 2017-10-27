#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; i++) 

using namespace std;

int main()
{
    int n, q;
    while (cin >> n >> q, n) {
        vector<int> dt(101, 0); 
        rep(i, n) {
            int tmp;
            cin >> tmp;
            rep(j, tmp) {
                int t;
                cin >> t;
                dt[t]++;
            }
        }
        int max = 0;
        rep(j, 101) {
            if (dt[j] > dt[max]) {
                max = j;
            }
        }
        if (dt[max] >= q) {
            cout << max << endl;
        } else {
            puts("0");
        }
    }
    return 0;
}


