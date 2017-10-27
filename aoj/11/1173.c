#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[101];
char stack[101];
int pos;

void scan_data(void);

int main(void)
{
    int i, fl = 0;
    scan_data();
    while (strcmp(input, ".")) {
        fl = 0;
        i = 0;
        pos = 0;
        while (input[i] != '\0') {
            if (input[i] == '(') {
                stack[pos++] = '(';
            } else if (input[i] == '[') {
                stack[pos++] = '[';
            } else if (input[i] == ')') {
                if (pos == 0 || stack[--pos] != '(') {
                    fl = 1;
                    break;
                }
            } else if (input[i] == ']') {
                if (pos == 0 || stack[--pos] != '[') {
                    fl = 1;
                    break;
                }
            }
            i++;
        }
        if (pos != 0) {
            fl = 1;
        }
        if (fl) {
            puts("no");
        } else {
            puts("yes");
        }
        scan_data();
    }
    return 0;
}

void scan_data(void)
{
    char a;
    int i = 0;
    a = getchar();
    while (a != '\n') {
        input[i] = a;
        a = getchar();
        i++;
    }
    input[i] = '\0';
}

