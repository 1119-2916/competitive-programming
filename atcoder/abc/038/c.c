#include <stdio.h>

int input[100001];

int main(void)
{
    int n, i, j;
    long long int ans = 0, count;
    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        scanf("%d",&input[i]);
    }

    i = 0;
    while (i < n) {
        count = 1;
        while (i < n && input[i] < input[i+1]) {
            count++;
            i++;
        }
        //printf("%d\n",count);
        ans += (count) * (count + 1) / 2;
        i++;
    }
    printf("%lld\n",ans);
    return 0;
}


