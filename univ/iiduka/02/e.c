#include <stdio.h>

int can_x[100000];
int can_y[100000];
int x, y;
int n;

int main(void)
{
    int i, max, max_x;
    scanf("%d %d",&x, &y);

    while (x != 0 && y != 0) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) {
            scanf("%d %d",&can_x[i], &can_y[i]);
        }
        max = can_x[0] - x + can_y[0] - y;
        max_x = 0;
        for (i = 1; i < n; i++) {
            if (max > can_x[i] - x + can_y[i] - y) {
                 max = can_x[i] - x + can_y[i] - y;
                 max_x = i;
            }
        }
        printf("%d


        




