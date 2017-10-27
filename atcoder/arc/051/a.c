#include <stdio.h>

int x1, y1, r, x2, y2, x3, y3;

int bl(int a, int b);

int main(void)
{
    int enx[4], eny[4], red = 0, blue = 0, i;
    scanf("%d %d %d %d %d %d %d",&x1,&y1,&r,&x2,&y2,&x3,&y3);
    enx[0] = x1-r; eny[0] = y1-r;
    enx[1] = x1-r; eny[1] = y1+r;
    enx[2] = x1+r; eny[2] = y1-r;
    enx[3] = x1+r; eny[3] = y1+r;
    for (i = 0; i < 4; i++) {
        if (enx[i] < x2 || enx[i] > x3 || eny[i] < y2 || eny[i] > y3) {
            red = 1;
        }
    }
    blue = bl(x2,y2);
    blue = bl(x3,y2);
    blue = bl(x2,y3);
    blue = bl(x3,y3);
    if (red) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    if (blue) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}

int bl(int a, int b) 
{
    if ((a - x1)*(a - x1) + (b - y1)*(b - y1) > r*r) {
        return 1;
    } else {
        return 0;
    }
}



