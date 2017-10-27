#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUT_NUMBER 1000000000
#define MAX_INPUT_DATA 100000
#define MAX_DATASET 40

int dp_table[MAX_INPUT_DATA];
int data_set[MAX_INPUT_DATA];
int t, p, n, count;

void dp(int look, int add);

int main(void) 
{
    int data_case, i, j;
    scanf("%d",&t);
    for (data_case = 1; data_case <= t; data_case++) {
        count = 0;
        scanf("%d %d",&n, &p);
        for (i = 0; i < n; i++) {
            scanf("%d",&data_set[i]);
            dp_table[i] = data_set[i];
            if(data_set[i] <= p) {
                count++;
            }
        }
        for (i = 1; i < n; i++) {
            dp(0, i);
        }
        printf("Case #%d: %d\n",data_case, count);
    }
    return 0;
}

void dp(int look, int add)
{
    long long int tmp;
    if (dp_table[look]) {
        tmp = dp_table[look] + data_set[add];
        //printf("%lld\n",tmp);
        if (tmp <= p) {
            count++;
            dp_table[look] = tmp;
        } else {
            dp_table[look] = 0;
        }
    }
    if (add != n-1) {
        dp(look+1, add+1);
    }
}




        
