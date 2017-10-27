#include <stdio.h>
#include <string.h>

char input[1025];
int count;
char left[16] = "qwertasdfgzxcvb";
char right[12] = "yuiophjklnm";

int check(char a);

int main(void)
{
    int i, j, now, tmp, len;
    scanf("%s",input);
    while (input[0] != '#') {
        len = strlen(input);
        count = 0;
        now = check(input[0]);
        for (i = 1; i < len; i++) {
            tmp = check(input[i]);
            if (tmp != now) {
                count++;
                now = tmp;
            }
        }
        printf("%d\n",count);
        scanf("%s",input);
    }
    return 0;
}
 
int check(char a)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (a == left[i]) {
            return 1;
        } 
    }
    for (i = 0; i < 12; i++) {
        if (a == right[i]) {
            return -1;
        }
    }
    return 0;
}

        
        



