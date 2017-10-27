#include <stdio.h>
#define MOD 1000000007

int main(void)
{
    long long int a = 0, b = 1, tmp, loop = 100;
    while (loop--) {
        printf("%lld\n", (a + b) % MOD);
        tmp = a + b;
        a = b;
        b = tmp;
        b %= MOD;
    }
    return 0;
}
