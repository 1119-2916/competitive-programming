#include <stdio.h>
#define MAX 246999

int elatosthenes[MAX];

void prime(void) {
    int i, j;
    for(i = 2; i < MAX / 2; i++) {
        if(!elatosthenes[i]) {
            for(j = 2; i*j < MAX; j++) {
                elatosthenes[i*j] = 1;
            }
        }
    }
}

int main(void) {
    int n, count, i;
    prime();
    scanf("%d",&n);
    while(n) {
        count = 0;
        for(i = n+1; i <= 2*n; i++) {
            if(!elatosthenes[i]) {
                count++;
            }
        }
        printf("%d\n",count);
        scanf("%d",&n);
    }
    return 0;
}
            



