#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[301], bubunn[301];
int len;

int main(void) {
    int i, k, j, count;
    char *tmp;
    scanf("%s",string);
    scanf("%d",&k);
    len = strlen(string);
    if(len < k) {
        puts("0");
        return 0;
    }
    count = 0;
    for(i = 0; i <= len-k; i++) {
        strncpy(bubunn, string+i, sizeof(char) * k);
        //printf("%s\n",bubunn);
        tmp = strstr(string, bubunn);
        if(string + i == tmp) {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
        



