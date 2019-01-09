#include <stdio.h>

int main(void) {
    int a[1001], b[1001];
    int n, m, i, count, j;
    int max, max_i;
    scanf("%d %d",&n,&m);
    while(n != 0) {
        max = 0;
        max_i = 0;
        for(i = 0; i < n; i++) {
            scanf("%d %d",&a[i], &b[i]);
        }
        for(i = 0; i < m; i++) {
            count = 0;
            for(j = 0; j < n; j++) {
                if(a[j] <= i && i <= b[j]) {
                    count++;
                }
            }
            if(count > max) {
                max_i = i;
                max = count;
            }
        }
        printf("%d\n",max_i);
        scanf("%d %d",&n, &m);
    }
    return 0;
}

