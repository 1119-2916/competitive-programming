#include <stdio.h>
#define BAN 32

int board[BAN][BAN];
int clear[2];
int x[4] = {0, 1, 0, -1};
int y[4] = {-1, 0, 1, 0};

int find_max(void);
void board_reset(void);
int find_next(void);
void te(void);

int main(void)
{
    int i, j, max, max_x, max_y;
    board_reset();

    while (find_max()) {
        te();
        puts("");
    }
    return 0;
}

void te(void)
{
    int c0 = clear[0], c1 = clear[1];
    int tmp;

    printf("%d %d\n",c0, c1);
    board[c0][c1]--;

    tmp = find_next();
    if (tmp != -1) {
        clear[0] += x[tmp];
        clear[1] += y[tmp];
        te();
    }
}

int find_next(void)
{
    int i, j, num = board[clear[0]][clear[1]];
    if (!num) {
        return -1;
    }
    for (i = 0; i < 4; i++) {
        if (num == board[clear[0]+x[i]][clear[1]+y[i]]) {
            return i;
        }
    }
    return -1;
}

int find_max(void)
{
    int i, j;
    int max = 0, fl = 0;
    for (i = 1; i < BAN-1; i++) {
        for (j = 1; j < BAN-1; j++) {
            if (board[i][j] > max) {
                max = board[i][j];
                fl = 1;
                clear[0] = i;
                clear[1] = j;
            }
        }
    }
    return max;
}

void board_reset(void) 
{
    int i, j;
    for (i = 0; i < BAN; i++) {
        for (j = 0; j < BAN; j++) {
            if (i != 0 && i != 31 && j != 0 && j != 31) {
                scanf("%d",&board[i][j]);
            } else {
                board[i][j] = -10;
            }
        }
    }
}

