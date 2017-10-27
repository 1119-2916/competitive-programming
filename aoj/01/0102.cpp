#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int data[10][10];
    int n;

    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> data[i][j];
            }
        }
        int ans;
        for (int i = 0; i < n; i++) {
            ans = 0;
            for (int j = 0; j < n; j++) {
                printf("%5d", data[i][j]);
                ans += data[i][j];
            }
            printf("%5d\n", ans);
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += data[j][i];
            }
            printf("%5d", sum);
            s += sum;
        }
        printf("%5d\n", s);
    }
    return 0;
}

