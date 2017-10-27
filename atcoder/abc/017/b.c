#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, len;
    char input[51];
    
    scanf("%s",input);

    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (input[i] == 'o') {
            continue;
        } else if (input[i] == 'k') {
            continue;
        } else if (input[i] == 'u') {
            continue;
        } else if (input[i] == 'c') {
            if (len <= i) {
                puts("NO");
                return 0;
            }
            if (input[i+1] == 'h') {
                i++;
                continue;
            } else {
                puts("NO");
                return 0;
            }
        } else {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
            


    

