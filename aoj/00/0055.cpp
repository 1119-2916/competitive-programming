#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    double n;
    while (cin >> n) {
        double ans = n;
        for (int i = 2; i <= 10; i++) {
            if (i % 2) {
                n /= 3;
                ans += n;
            } else {
                n *= 2;
                ans += n;
            }
        }
        printf("%.9lf\n", ans);
    }
    return 0;
}

