#include <stdio.h>

int num[50];
int len;

int solve(int n);
int make(int a, int b);

int main(void)
{
    int i, j, max, ans, ans_i;

    scanf("%d",&len);

    for (i = 0; i < len; i++) {
        scanf("%d",&num[i]);
    }

    ans = solve(0);
    for (i = 1; i < len; i++) {

        max = solve(i);
        //printf("%d: %d\n", i, max);

        if (max > ans) {
            ans = max;
        }
    }

    printf("%d\n",ans);

    return 0;
}

int solve(int n)
{
    int i, j, max, sum, ans, gu, ki;
    
    max = -10000;

    //前

    sum = 0;
    for (i = n+1; i < len; i += 2) {
        sum += num[i];
        if (sum > max) {
            max = sum;
            ans = make(n, i-1);
        }
    }

    sum = 0;
    gu = 0;
    ki = 0;

    for (i = n; i > 0; i--) {
        if (i % 2) {
            gu += num[i];
            if (gu >= max) {
                max = gu;
                ans = make(i-1, n);
            }
        } else {
            ki += num[i];
            if (ki >= max) {
                max = ki;
                ans = make(i-1, n);
            }
        }
    }
    //printf(" %d ",max);

    return ans;
}

int make(int a, int b) 
{
    int i, ans = 0;

    for (i = a; i <= b; i+= 2) {
        ans += num[i];
    }
    
    return ans;
}

