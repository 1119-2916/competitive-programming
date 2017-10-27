#include <stdio.h>
#define BAN 21

int board[BAN][BAN], gem;

int main(void)
{
    int i, j, tx, ty, tn, px, py, fl, com;
    char tc[2];
    scanf("%d",&gem);
    while (gem) {
        for (i = 0; i < BAN; i++) {
            for (j = 0; j < BAN; j++) {
                board[i][j] = 0;
            }
        }
        px = 10; py = 10;
        fl = 0;

        for (i = 0; i < gem; i++) {
            scanf("%d %d",&tx, &ty);
            board[tx][ty] = 7;
        }
        scanf("%d",&com);
        for (i = 0; i < com; i++) {
            scanf("%s %d",tc, &tn);
            if (tc[0] == 'N') {
                for (j = 0; j < tn; j++) {
                    py++;
                    if (board[px][py] == 7) {
                        board[px][py] = 0;
                    }
                }
            } else if (tc[0] == 'E') {
                for (j = 0; j < tn; j++) {
                    px++;
                    if (board[px][py] == 7) {
                        board[px][py] = 0;
                    }
                }
            } else if (tc[0] == 'S') {
                 for (j = 0; j < tn; j++) {
                    py--;
                    if (board[px][py] == 7) {
                        board[px][py] = 0;
                    }
                }
            } else if (tc[0] == 'W') {
                 for (j = 0; j < tn; j++) {
                    px--;
                    if (board[px][py] == 7) {
                        board[px][py] = 0;
                    }
                }
            }
        }
        for (i = 0; i < BAN; i++) {
            for (j = 0; j < BAN; j++) {
                if (board[i][j] == 7) {
                    fl = 1;
                }
            }
        }
        if (fl) {
            puts("No");
        } else {
            puts("Yes");
        }
        scanf("%d",&gem);
    }
    return 0;
}


    
    
