#include <stdio.h>
#include <math.h>

int board[82][82];
int n, r;

void board_reset(void);

int main(void)
{
    int i, j, k;
    int xs, xt, h, yy, pos_y;
    double a, b, y;
    scanf("%d %d",&r, &n);

    while (r) {
        board_reset();
        for (i = 0; i < n; i++) {
            scanf("%d %d %d",&xs, &xt, &h);
            xs += 20;
            xt += 20;
            xs *= 2;
            xt *= 2;
            xs++;
            xt++;
            h += 41;
            for (j = xs; j <= xt; j++) {
                for (k = 40; k <= h; k++) {
                    board[j][k] = 1;
                }
            }
        }

        /*        for (i = 82; i >= 0; i--) {
                  for (j = 82; j >= 0; j--) {
                  printf("%d ",board[j][i]);
                  }
                  puts("");
                  }*/
        for (a = 0; a < 41; a += 0.001) {
            for (i = 40 - (r * 2); i <= 40 + (r * 2); i++) {
                yy = r * r - i * i;
                y = sqrt((double)yy);
                y += a;
                if (y / 1 != 0) {
                    pos_y = (int)y + 1;
                } else {
                    pos_y = (int)y;
                }
                if (!board[i][pos_y]) {
                    printf("%f\n",(a-0.001)/2);
                    break;
                    break;
                }
            }
        }
        scanf("%d %d",&r, &n);
    }

    return 0;
}

void board_reset(void)
{
    int i, j;
    for (i = 0; i < 82; i++) {
        for (j = 0; j < 41; j++) {
            board[i][j] = 1;
        }
        for (;j < 82; j++) {
            board[i][j] = 0;
        }
    }
}
