#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main()
{
    char a;
    int ans = 0;
    a = getchar();
    while (a != EOF) {
        if ('0' <= a && a <= '9') {
            int num = a - '0';
            a = getchar();
            while ('0' <= a && a <= '9') {
                num *= 10;
                num += a - '0';
                a = getchar();
            }
            ans += num;
        } else {
            a = getchar();
        }
    }

    cout << ans << endl;

    return 0;
}
