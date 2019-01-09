#include <stdio.h>

int main(void) {
    int h, m, count;
    scanf("%d",&h);
    while(h != 0) {
        scanf("%d",&m);
        count = 0;
        while(m > 0) {
            count++;
            m -= (h + h);
        }
        if(m == 0 || count > 1){
            printf("%d\n",count);
        } else {
            printf("%d\n",count + 1);
        }
        scanf("%d",&h);
    }
    return 0;
}

