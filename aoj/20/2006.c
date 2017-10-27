#include <stdio.h>
#include <string.h>

char input[101000];
char ans[78];
int len, pos;

int main(void)
{
    int i, j, tmp, in;
    int aa = 0;
    scanf("%d", &tmp);
    while (scanf("%s",input) != EOF) {
        pos = 0;
        aa = 0;
        len = strlen(input);
        tmp = 0;
        for (i = 0; i < len; i++) {
            if (input[i] != '0') {
                tmp++;
                in = input[i] - '0';
            } else {
                if (tmp) {
                    if (in == 1) {
                        tmp--;
                        tmp %= 5;
                        if (tmp == 0) {
                            ans[aa++] = '.';
                        } else if (tmp == 1) {
                            ans[aa++] = ',';
                        } else if (tmp == 2) {
                            ans[aa++] = '!';
                        } else if (tmp == 3) {
                            ans[aa++] = '?';
                        } else if (tmp == 4) {
                            ans[aa++] = ' ';
                        }
                    } else if (in == 2) {
                        tmp--;
                        tmp %= 3;
                        ans[aa++] = 'a' + tmp;
                    } else if (in == 3) {
                        tmp--;
                        tmp %= 3;
                        ans[aa++] = 'd' + tmp;
                    } else if (in == 4) {
                        tmp--;
                        tmp %= 3;
                        ans[aa++] = 'g' + tmp;
                    } else if (in == 5) {
                        tmp--;
                        tmp %= 3;
                        ans[aa++] = 'j' + tmp;
                    } else if (in == 6) {
                        tmp--;
                        tmp %= 3;
                        ans[aa++] = 'm' + tmp;
                    } else if (in == 7) {
                        tmp--;
                        tmp %= 4;
                        ans[aa++] = 'p' + tmp;
                    } else if (in == 8) {
                        tmp--;
                        tmp %= 3;
                        ans[aa++] = 't' + tmp;
                    } else if (in == 9) {
                        tmp--;
                        tmp %= 4;
                        ans[aa++] = 'w' + tmp;
                    }
                    in = 0;
                    tmp = 0;
                }
            }
        }
        ans[aa] = 0;
        printf("%s\n", ans);
    }
    return 0;
}

