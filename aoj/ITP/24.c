#include <stdio.h>

int main(void)
{
    int w, h, x, y, r;
    scanf("%d %d %d %d %d", &w, &h, &x, &y, &r);

    if ( 0 <= (x-r) && (x+r) <= w 
            && 0 <= (y-r) && (y+r) <= h) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}
