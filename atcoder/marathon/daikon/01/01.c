#include <stdio.h>
#define BAN 30
int board[BAN][BAN];
int clear[2];

int find_max(void);

int main(void)
{
    int i, j, max, max_x, max_y;
    for (i = 0; i < BAN; i++) {
        for (j = 0; j < BAN; j++) {
            scanf("%d",&board[i][j]);
        }
    }
    while (find_max()) {
        printf("%d %d\n",clear[0]+1, clear[1]+1);
        board[clear[0]][clear[1]]--;
    }
    return 0;
}

int find_max(void)
{
    int i, j;
    int max = 0, fl = 0;
    for (i = 0; i < BAN; i++) {
        for (j = 0; j < BAN; j++) {
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
