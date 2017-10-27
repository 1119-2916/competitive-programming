#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    double a, b;
    while (cin >> a >> b, a || b) {
        printf("%.9lf\n", a*a + a*2*sqrt((a*a)/4+b*b));
    }

    return 0;
}
