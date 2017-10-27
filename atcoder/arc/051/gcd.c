#include <stdio.h>

int counter = 0;

int gcd(int a, int b) 
{
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
}

int main(void)
{
    int a, b;
    while (scanf("%d %d",&a, &b) != EOF) {
        counter = 0;
    gcd(a,b);
    printf("%d %d %d\n",counter, a, b);
    }
}



