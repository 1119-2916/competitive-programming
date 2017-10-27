#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct pair{
    float x;
    float y;
};

struct pair berry[10];

int main(void)
{
    float w, h, n, a;
    int i, j;
    int k;
    int flag = 0;
    int up, down;

    scanf("%f %f %f",&h, &w, &n);

    for (k = 0; k < n; k++) {
        scanf("%f %f",&berry[k].x, &berry[k].y);
    }

    /*if (n % 2) {
        puts("-1");
        return 0;
    }*/
    for (i = 1; i < w; i++) {
        a = (float)i;
        up = 0;
        down = 0;
        for (j = 0; j < n; j++) {
            if (berry[j].y == berry[j].x * (5/i)) {
                up = -1;
                break;
            } else if (berry[j].y > berry[j].x * (5/i)) {
                up++;
            } else {
                down++;
            }
        }
        if (up == down) {
            flag = 1;
            printf("(%d,5)\n",(int)i);
        }
    }

    for (i = 1; i <= h; i++) {
        a = (double)i;
        up = 0;
        down = 0;
        for (j = 0; j < n; j++) {
            if (berry[j].y == berry[j].x * (a/5)) {
                up = -1;
                break;
            } else if (berry[j].y > berry[j].x * (a/5)) {
                up++;
            } else {
                down++;
            }
        }
        if (up == down) {
            flag = 1;
            printf("(5,%d)\n",(int)i);
        }
    }

    if (!flag) {
        puts("-1");
    }
    return 0;
}
















