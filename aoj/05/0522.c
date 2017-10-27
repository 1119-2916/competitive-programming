#include <stdio.h>
#include <string.h>

char input[10001];

int main(void)
{
    int i, len, j, joi = 0, ioi = 0;
    while (scanf("%s",input) != EOF) {
        joi = 0;
        ioi = 0;
        len = strlen(input);
        for (i = 0; i < len-2; i++) {
            if (strncmp("JOI", &input[i], 3) == 0) {
                joi++;
            }
        }
        for (i = 0; i < len-2; i++) {
            if (strncmp("IOI", &input[i], 3) == 0) {
                ioi++;
            }
        }
        printf("%d\n%d\n",joi, ioi);
    }
    return 0;
}
