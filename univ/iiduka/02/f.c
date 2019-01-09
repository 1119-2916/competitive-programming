#include <stdio.h>
#include <string.h>

int alp[26][26];
int st, num;
char tmp[21];

int main(void)
{
    int i, j, k;
    int len;
    int flag;
    int ans;
    scanf("%d %d",&st, &num);
    while (num != 0) {
        flag = 0;
        for (i = 0; i < 26; i++) {
            for (j = 0; j < 26; j++) {
                alp[i][j] = 0;
            }
        }

        for (i = 0; i < num; i++) {
            scanf("%s",tmp);
            len = strlen(tmp);
            alp[tmp[0]-'a'][tmp[len-1]-'a'] = 1;
        }
        for (i = 0; i < 26; i++) {
            for (j = 0; j < 26; j++) {
                if (alp[i][j]) {
                    ans = 0;
                    for (k = 0; k < 26; k++) {
                        if (alp[j][k]) {
                            ans = 1;
                        }
                    }
                    if (!ans) {
                        flag = 1;
                    }
                }
            }
        }

        if (flag) {
            if (st) {
                puts("win");
            } else {
                puts("lose");
            }
        } else {
            puts("?");
        }
        scanf("%d %d",&st, &num);
    }
    return 0;
}





