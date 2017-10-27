#include <stdio.h>

int main(void) {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf",&a, &b, &c, &d);
    if(b/a > d/c) {
        puts("TAKAHASHI");
    } else if(b/a < d/c) {
        puts("AOKI");
    } else {
        puts("DRAW");
    }
    return 0;
}
