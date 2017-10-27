#include <stdio.h>

char name[52] = "DiscoPresentsDiscoveryChannelProgrammingContest2016";

int main(void)
{
    int n, i, j, flag = 0;
    scanf("%d",&n);
    for (i = 0, j = 1; i < 51; i++, j++) {
        flag = 0;
        printf("%c",name[i]);
        if (j == n) {
            puts("");
            j = 0;
            flag = 1;
        }
    }
    if (!flag) {
        puts("");
    }
    return 0;
}

