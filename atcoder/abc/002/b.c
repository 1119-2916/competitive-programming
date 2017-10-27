#include <stdio.h>
#include <string.h>

char word[31];
int len;

int main(void)
{
    int i;
    scanf("%s",word);
    len = strlen(word);
    for (i = 0; i < len; i++) {
        if (word[i] != 'a' &&word[i] != 'i' &&word[i] != 'u' &&
                word[i] != 'e' &&word[i] != 'o') {
            printf("%c",word[i]);
        }
    }
    puts("");
    return 0;
}
