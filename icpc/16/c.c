#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 7368792 

int board[INF];

int main(void)
{
    int count;
    int i, j, n, m, k;
    scanf("%d %d", &m, &n);
    while (n) {
        for (i = 0; i < INF; i++) {
            board[i] = 0;
        }
        count = 0;
        for (j = m; j < INF; j++) {
            if (!board[j]) {
                count++;
                for (k = j; k < INF; k+=j) { 
                    board[k] = 1;
                }
                if (count == n) {
                    break;
                }
            }
        }
        for (i = m; i < INF; i++) {
            if (!board[i]) {
                printf("%d\n", i);
                break;
            }
        }
        scanf("%d %d", &m, &n);
    }
    return 0;
}
