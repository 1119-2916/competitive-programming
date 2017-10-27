#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main(void) 
{
    double n, k;

    scanf("%lf",&n);

    n--;

    k = (18.0 * 60) / n;

    printf("%lf\n",k);

    return 0;
}

