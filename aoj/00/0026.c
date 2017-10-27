#include <stdio.h>

int board[10][10];

int main(void)
{
    int i, j, size, x, y, count = 0, max = 0;
    int dx[12] = {-1, 0, 1, 0, -1, -1, 1, 1, -2, 0, 2, 0};
    int dy[12] = {0, 1, 0, -1, 1, -1, 1, -1, 0, -2, 0, 2};
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }
    while (scanf("%d,%d,%d", &x, &y, &size) != EOF) {
        board[x][y]++;
        if (size == 1) {
            for (i = 0; i < 4; i++) {
                if (0 <= x + dx[i] && x + dx[i] < 10 
                        && 0 <= y + dy[i] && y + dy[i] < 10) {
                    board[x+dx[i]][y+dy[i]]++;
                }
            }
        } else if (size == 2) {
            for (i = 0; i < 8; i++) {
                if (0 <= x + dx[i] && x + dx[i] < 10 
                        && 0 <= y + dy[i] && y + dy[i] < 10) {
                    board[x+dx[i]][y+dy[i]]++;
                }
            }
        } else if (size == 3) {
            for (i = 0; i < 12; i++) {
                if (0 <= x + dx[i] && x + dx[i] < 10 
                        && 0 <= y + dy[i] && y + dy[i] < 10) {
                    board[x+dx[i]][y+dy[i]]++;
                }
            }
        }
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (!board[i][j]) {
                count++;
            }
            if (board[i][j] > max) {
                max = board[i][j];
            }
        }
    }
    printf("%d\n%d\n", count, max);
    return 0;
}




            
