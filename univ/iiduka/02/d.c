#include <stdio.h>

int a, b, d, c;

int main(void)
{
    double mae, ato;

    scanf("%d %d %d %d",&a, &b, &c, &d);

    while (a != 0) {
        mae = (double)b/(double)a;
        ato = (double)d/(double)c;
        if (mae < ato) {
            printf("%d %d\n",c, d);
        } else if (mae > ato) {
            printf("%d %d\n",a, b);
        } else {
            puts("draw");
        }
        scanf("%d %d %d %d",&a, &b, &c, &d);
    }
    return 0;
}
