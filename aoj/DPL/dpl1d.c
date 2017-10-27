#include <stdio.h>
#define MAX_INPUT 100000
#define MAX_NUM 1000000001

int n, input[MAX_INPUT];
int dp[MAX_INPUT];

void bsearch(int n, int st, int en);

int main(void)
{
    int i, j;

    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        scanf("%d",&input[i]);
    }

    for (i = 0; i < MAX_INPUT; i++) {
        dp[i] = MAX_NUM;
    }

    for (i = 0; i < n; i++) {
        bsearch(input[i], 0, i);
    }

    for (i = 0; i < n; i++) {
        if (dp[i] == MAX_NUM) {
            break;
        }
    }

    printf("%d\n",i);
    return 0;
}

void bsearch(int n, int st, int en) 
{
    if ((st+en)/2 == st || (st+en)/2 == en) {
        if (n == dp[st]) {
            return ;
        } else if (n < dp[st]) {
            dp[st] = n;
        } else {
            dp[en] = n;
        }
    } else if (n < dp[(st+en)/2]) {
        bsearch(n, st, (st+en)/2);
    } else {
        bsearch(n, (st+en)/2, en);
    }
}


