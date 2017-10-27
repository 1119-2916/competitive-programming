#include <stdio.h>
#define MAX_INPUT 100000

long long int table1[MAX_INPUT];
long long int table2[MAX_INPUT];

int n, max;
long long int tmp;

int main(void) {
    int i, j, flag = 0, flag3 = 0, *temp;
    scanf("%d %d",&n, &max);
    for(i = 0; i < n; i++) {
        scanf("%lld",&table1[i]);
        if(table1[i] == 0) {
            flag3 = 1;
        } else if(table1[i] <= max) {
            flag = 1;
        } else if(table1[i] > max) {
            table1[i] = 0;
        }
    }
    if(flag3) {
        printf("%d\n",n);
        return 0;
    }
    if(!flag) {
        puts("0");
        return 0;
    }
    for(i = 0; i < n; i++) {
        flag = 0;
        for(j = 1; j < n-i; j++) {
            tmp = table1[j-1] * table1[j];
            if(tmp <= max && tmp != 0) {
                flag = 1;
                table2[j-1] = tmp;
            } else {
                table2[j-1] = 0;
            }
        }
        if(flag) {
            for(j = 0; j < n; j++) {
                table1[j] = table2[j];
            }
        } else {
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("%d\n",i);
    return 0;
}

