#include <stdio.h>

int main(void)
{
    long long int ret = 1;
    for (int i = 0; i < 50; i++) {
        ret *= 2;
    }
    printf("%lld\n", ret);
    return 0;
}
