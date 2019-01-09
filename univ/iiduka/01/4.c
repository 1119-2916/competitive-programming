#include <stdio.h>

int prob[1000][2];

int main(void) {
    int n, m, ai, bi;
    int i, tmp, j;
    int count, max_count, max_i;
    scanf("%d %d",&n,&m);
    while(n != 0) {
        for(i = 0; i < n; i++) {
            scanf("%d%d",&prob[i][0], &prob[i][1]);
        }
        for(i = 0; i < n-1; i++) {
            for(j = i; j < n-1; j++) {
                if(prob[j][0] > prob[j+1][0]) {
                    tmp = prob[j][0];
                    prob[j][0] = prob[j+1][0];
                    prob[j+1][0] = tmp;

                    tmp = prob[j][1];
                    prob[j][1] = prob[j+1][1];
                    prob[j+1][1] = tmp;
                }
            }
        }
        max_count = 0;
        max_i = 0;
        count = 0;
        for(i = 0; i < m; i++) {
            count = 0;
            for(j = 0; j < n; j++) {
                if(prob[j][1] >= i && prob[j][0] <= i) {
                    count++;
                }
                if(prob[j][0] > i) {
                    break;
                }

            }
            if(count > max_count) {
                max_count = count;
                max_i = i;
            }
        }
        printf("%d\n",max_i);
        scanf("%d %d",&n,&m);
    }
    return 0;
}




