#include <stdio.h>

int now, right, left, count;

int cmp_char(char a[], char b[]);

int main(void)
{
    char input[3];
    int data, i;

    scanf("%d",&data);
    while (data) {
        count = 0;
        now = -1;
        right = -1;
        left = -1;
        for (i = 0; i < data; i++) {
            scanf("%s",input);
            if (cmp_char(input, "lu")) {
                left = 1;
            } else if (cmp_char(input, "ld")) {
                left = -1;
            } else if (cmp_char(input, "ru")) {
                right = 1;
            } else if (cmp_char(input, "rd")) {
                right = -1;
            }
            if (now != right && now != left) {
                now = right;
                count++;
            }
        }
        printf("%d\n",count);
        scanf("%d",&data);
    }
    return 0;
}

int cmp_char(char a[], char b[])
{
    int i;
    for (i = 0; i < 2; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

