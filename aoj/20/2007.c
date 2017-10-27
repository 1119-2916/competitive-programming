#include <stdio.h>

int c10, c50, c100, c500, price;
int a10, a50, a100, a500;

int main(void)
{
    int tmp;
    scanf("%d",&price);

    while (price) {
        scanf("%d %d %d %d",&c10, &c50, &c100, &c500);
        a10 = 0;
        a50 = 0;
        a100 = 0;
        a500 = 0;
        
        if (price % 50) {
            if ((price % 50) <= c10 * 10) {
                c10 -= (price % 50) / 10;
                a10 = (price % 50) / 10;
                price -= (price % 50);
            } else {
            //
            }
        }

        if (price && price % 100) {
            if ((price % 100) <= c50 * 50) {
                c50--;
                a50++;
                price -= (price % 100);
            } else {
            //
            }
        }

        if (price > 0 && price % 500) {
            if ((price % 500) <= c100 * 100) {
                if (price % 100) {
                    c100 -= (price % 500) / 100 + 1;
                    a100 = (price % 500) / 100 + 1;
                } else {
                    c100 -= (price % 500) / 100;
                    a100 = (price % 500) / 100;
                }
                price -= (price % 500);
            } else {
            //
            }
        }

        while (price > 0 && c10 >= 5) {
            c10 -= 5;
            a10 += 5;
            price -= 50;
        }

        while (price > 0 && c50 >= 2) {
            c50 -= 2;
            a50 += 2;
            price -= 100;
        }

        while (price > 0 && c100 >= 5) {
            c100 -= 5;
            a100 += 5;
            price -= 500;
        }

        if (price > 0) {
            if (price % 500) {
                a500 = price / 500 + 1;
            } else {
                a500 = price / 500;
            }
        }

        while (c10 >= 5) {
            c10 -= 5;
            a10 += 5;
        }

        while (c50 >= 2) {
            c50 -= 2;
            a50 += 2;
        }

        while (c100 >= 5) {
            c100 -= 5;
            a100 += 5;
        }

        if (a10) {
            printf("10 %d\n",a10);
        }

        if (a50) {
            printf("50 %d\n",a50);
        }

        if (a100) {
            printf("100 %d\n",a100);
        }
     
        if (a500) {
            printf("500 %d\n",a500);
        }
        puts("");

        scanf("%d",&price);
    }

    return 0;
}

