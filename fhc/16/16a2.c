#include <stdio.h>
#include <stdlib.h>

#define SIG(a) a*(a-1)/2
#define MAX_DATA 2000

struct pair{
    int x;
    int y;
};

int data, n, k, i, count, j, check, tmp;
struct pair input[MAX_DATA];
int sen[MAX_DATA];

int comp_sen(const void *a, const void *b);

int main(void) {
    scanf("%d",&data);
    for(k = 0; k < data; k++) {
        scanf("%d",&n);
        for(i = 0; i < n; i++) {
            scanf("%d %d",&input[i].x, &input[i].y);
        }
        count = 0;
        for(i = 0; i < n; i++) {

            for(j = 0; j < n; j++) {
                sen[j] = (input[i].x - input[j].x)
                        * (input[i].x - input[j].x) 
                        + (input[i].y - input[j].y)
                        * (input[i].y - input[j].y);
            }
            qsort(sen, n, sizeof(int), comp_sen);
            for(j = 0; j < n; j++) {
                printf("%d\n",sen[j]);
            }
            check = 1;
            tmp = sen[0];
            for(j = 1; j < n; j++) {
                if(tmp != sen[j]) {
                    count += SIG(check);
                    check = 1;
                    tmp = sen[j];
                } else {
                    check++;
                }
            }
            count += SIG(check);
            printf("---%d---\n",count);

        }
        printf("Case #%d: %d\n", k+1, count);
    }
    return 0;
}

int comp_sen(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}




