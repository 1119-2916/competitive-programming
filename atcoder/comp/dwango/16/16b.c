#include <stdio.h>

#define MAX 100000

int main(void)
{
    int pen[MAX], n;

    int i, min;

    scanf("%d",&n);
    n--;

    for (i = 0; i < n; i++) {
        scanf("%d",&pen[i]);
    }

    printf("%d ",pen[0]);

    for (i = 0; i < n-1; i++) {
        if (pen[i] < pen[i+1]) {
            min = pen[i];
        } else {
            min = pen[i+1];
        }
        printf("%d ",min);
    }

    printf("%d\n",pen[n-1]);

    return 0;
}

    
