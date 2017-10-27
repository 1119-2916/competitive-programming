#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char data[101];

int main(void) {
    int i, j, n;
    while(scanf("%s",data) != EOF) {
        n = strlen(data);
        for(i = 0; i < n; i++) {
            if(data[i] == '@') {
                for(j = 0; j < data[i+1] - '0'; j++) {
                    printf("%c",data[i+2]);
                }
                i += 2;
            } else {
                printf("%c",data[i]);
            }
        }
        puts("");
    }
    return 0;
}


