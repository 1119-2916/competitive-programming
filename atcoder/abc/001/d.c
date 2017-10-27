#include <stdio.h>

int time[481], n;

int clc(int a, int b);

int main(void)
{
    int i;
    int tmp_s, tmp_e, tmp = 0, fl;

    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        scanf("%d-%d",&tmp_s, &tmp_e);
        tmp_s = clc(0, tmp_s);
        tmp_e = clc(1, tmp_e);
        time[tmp_s]++;
        time[tmp_e]--;
    }

    for (i = 0; i < 481; i++) {
        if (tmp == 0) {
            fl = 0;
        } else {
            fl = 1;
        }
        tmp += time[i];
        if (!fl && tmp > 0) {
            if (i * 5 < 10) {
                printf("000");
            } else if (i * 5 < 100) {
                printf("00");
            } else if (i * 5 < 1000) {
                printf("0");
            }
            printf("%d-",i*5);
        } else if (fl && tmp == 0) {
            if (i * 5 < 10) {
                printf("000");
            } else if (i * 5 < 100) {
                printf("00");
            } else if (i * 5 < 1000) {
                printf("0");
            }
            printf("%d\n",i*5);
        }
    }
    return 0;
}

int clc(int a, int b)
{
    if (a) {
        if (56 <= b % 100 && b % 100 <= 59) {
            return (b / 100 + 1) * 100 / 5;
        } else {
            if (b % 5) {
                return b / 5 + 1;
            } else {
                return b / 5;
            }
        }
    } else {
        return b / 5;
    }
}








