#include <stdio.h>

int m, n, t;

int time[10000];
int input[100];

int main(void)
{
    int i, j, count = 0;
    scanf("%d %d %d",&n, &m, &t);
    for (i = 0; i < n; i++) {
        scanf("%d",&input[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = -m + input[i]; j < m + input[i]; j++) {
            if (j >= t) {
                break;
            }
            time[j] = 1;
        }
    }
    for (i = 0; i < t; i++) {
        //printf("%d %d\n",i, time[i]);
        if (time[i] == 0) {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}



