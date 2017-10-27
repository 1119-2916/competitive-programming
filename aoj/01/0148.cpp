#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        if (n % 39 > 9) {
            printf("3C%d\n", n % 39);
        } else if (n % 39 > 0) {
            printf("3C0%d\n", n % 39);
        } else {
            puts("3C39");
        }
    }
    return 0;
}

