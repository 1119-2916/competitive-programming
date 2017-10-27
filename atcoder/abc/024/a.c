#include <stdio.h>

int a, b, c, k, s, t;

int main(void)
{
    int mem;

    scanf("%d %d %d %d %d %d",&a, &b, &c, &k, &s, &t);

    if (s + t < k) {
        printf("%d\n",s * a + t * b);
    } else {
        printf("%d\n",s * a + t * b - c * (s + t));
    }
    return 0;
}

