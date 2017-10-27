#include <stdio.h>
#define min(a, b) a<b?a:b
#define max(a, b) a>b?a:b

long long int ans, n, x;

long long int f();

int main(void)
{
    scanf("%lld%lld", &n, &x);
    
    ans += n;

    ans += f(min(x, n-x), max(x, n-x));

    printf("%lld\n", ans);
    return 0;

}

long long int f(a, b)
long long int a, b;
{   long long int tmp;
    if (b % a) {
        tmp = (b/a)*a*2;
        return tmp + f(b%a, a);
    } else {
        return (b/a)*a*2-a;
    }
}

