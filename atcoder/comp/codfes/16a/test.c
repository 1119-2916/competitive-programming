#include <stdio.h>

int main(void)
{
    int i, j, ans = 0;;

    for (i = 0; i < 100001; i++) {
        for (j = 0; j < 100001; j++) {
            ans++;
        }
    }
    
    puts("END");

    return 0;
}
