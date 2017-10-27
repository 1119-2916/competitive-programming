#include <stdio.h>
#include <string.h>

char str[200001];
int length;

int main(void)
{
    int pos, ans = 0, s = 0;

    scanf("%s", str);

    length = strlen(str);

    pos = 0;
    while (pos < length) {
        if (str[pos] == 'S') {
            s++;
        } else if (s && str[pos] == 'T') {
            s--;
            ans += 2;
        }
        pos++;
    }

    printf("%d\n", length - ans);
    return 0;
}

