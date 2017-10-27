#include <stdio.h>

long long int fanc(int n);

int main(void)
{
    long long int ans;
    int n;
    scanf("%d",&n);
    printf("%lld\n",fanc(n));
    return 0;
}

long long int fanc(int n)
{
    if (n < 2) {
        return 1;
    } else {
        return (n * fanc(n-1));
    }
}

