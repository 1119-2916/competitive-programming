#include <stdio.h>
#define MOD 1000000007

long long int a, b, c, ans;

int main(void)
{
    int i;
    scanf("%lld %lld %lld", &a, &b, &c);
    ans = 1;
    ans *= a % MOD;
    ans %= MOD;
    ans *= b % MOD;
    ans %= MOD;
    ans *= c % MOD;
    ans %= MOD;
    printf("%lld\n", ans);
    return 0;
}

