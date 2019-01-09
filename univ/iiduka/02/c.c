#include <stdio.h>

int at, en;

int main(void)
{
    scanf("%d%d",&at,&en);

    while (en != 0) {
        if (en == at) {
            puts("0");
        } else {
            printf("%d\n",(en + 1) - at);
        }
        scanf("%d%d",&at,&en);
    }
    return 0;
}

