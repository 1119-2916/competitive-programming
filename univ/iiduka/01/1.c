#include <stdio.h>
#include <string.h>

int alp[26];

int main(void) {
    char a[101], b[101];
    int i, flag = 0;
    scanf("%s",a);
    while(a[0] != '0') {
        flag = 0;
        scanf("%s",b);
        for(i = 0; i < 26; i++) {
            alp[i] = 0;
        }
        for(i = 0; a[i] != '\0'; i++) {
            alp[a[i] - 'a'] = 1;
        }
        for(i = 0; b[i] != '\0'; i++) {
            if(alp[b[i] - 'a']) {
                puts("OK");
                flag = 1;
                break;
            }
        }
        if(!flag) {
            puts("NG");
        }
        scanf("%s",a);
    }
    return 0;
}





