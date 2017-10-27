#include <stdio.h>

int main(void)
{
    int num;
    double w, h, bmi;

    while ( scanf("%d,%lf,%lf", &num, &w, &h) != EOF) {
        bmi = w / h / h;
        //printf("%lf\n",bmi);
        if (bmi >= 25.0) {
            printf("%d\n",num);
        }
    }

    return 0;
}
