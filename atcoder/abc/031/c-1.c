#include <stdio.h>
#define MAX_NUM_LEN 50
#define MIN -1000000

int num[MAX_NUM_LEN];
int len;

int main(void) 
{
    int i, j, max, ans = MIN;

    scanf("%d",&len);

    for (i = 0; i < len; i++) {
        scanf("%d",&num[i]);
    }

    for (i = 0; i < len; i++) {

        max = solve(i);

        if (ans < max) {
            ans = max;
        }
    }

    printf("%d\n",ans);

    return 0;
}

int solve(int n) 
{
    int i, j, max, ans = MIN, sum = 0;

    for (i = 0; i < n; i++) {
        sum += 

        max = plus(i, n);
        if (max > ans) {
            ans = max;
        }
    }

    for (i = n+1; i < len; i++) {

        max = plus(n, i);
        if (max > ans) {
            ans = max;
        }
    }

