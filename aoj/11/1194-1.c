#include <stdio.h>
#include <math.h>

int board[420][420];
int n, r;

void board_reset(void);
int dtoi(double a);

int main(void)
{
    int i, j, k;
    int xs, xt, h, x, y, time, fl;
    int dx, dy;

    scanf("%d %d",&r, &n);

    while (r) {
        board_reset();
        r *= 10;
        for (i = 0; i < n; i++) {
            scanf("%d %d %d\n",&xs, &xt, &h);
            xs = (xs + 20 + 1) * 10;
            xt = (xt + 20 + 1) * 10;
            h = (h + 20 + 1) * 10;
            //printf("%d %d %d",xs, xt, h);
            for (j = xs; j <= xt; j++) {
                for (k = 209; k <= h; k++) {
                    board[j][k] = 1;
                }
            }
        }

/*        for (i = 419; i >= 0; i--) {
            for (j = 0; j < 420; j++) {
                printf("%d",board[j][i]);
            }
            puts("");
        }*/

        fl = 0;
        for (time = 1; time < 300001; time++) {
            for (x = 0; x <= r; x++) {

                //printf("(%d,%d)(r,x)\n",r*r, x*x);
                y = dtoi(sqrt((double)r*(double)r-(double)x*(double)x)
                        + (double)time * 0.001);
                dx = x + 210;
                dy = y + 210 - r;
                //printf("(%d,%d)(dx,dy)\n",dx, dy);
                if (!board[dx][dy]) {
                printf("(%d,%d)(dx,dy)\n",dx, dy);
                    printf("%lf\n",(time-1)*0.0001);
                    fl = 1;
                    break;
                }

                //printf("(%d,%d)(r,x)\n",r*r, x*x);
                dx = -x + 210;
                //printf("(%d,%d)(dx,dy)\n",dx, dy);
                if (!board[dx][dy]) {
                printf("(%d,%d)(dx,dy)\n",dx, dy);
                    printf("%lf\n",(time-1)*0.0001);
                    fl = 1;
                    break;
                }

            }
            if (fl) break;
        }
        scanf("%d %d",&r, &n);
    }
}

void board_reset(void)
{
    int i, j;
    for (i = 0; i < 420; i++) {
        for (j = 0; j < 210; j++) {
            board[i][j] = 1;
        }
        for (;j < 420; j++) {
            board[i][j] = 0;
        }
    }
}

int dtoi(double a) 
{
        if (a - (int)a) {
            return (int)a+1;
        } else {
            return (int)a;
        }
}

