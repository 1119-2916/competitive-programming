#include <stdio.h>

int n, b;

int main(void)
{
    int i, j, count;
    int mae, usi;

    scanf("%d %d",&n, &b);

    mae = n; 
    usi = n;
    while (1) {
        if (mae == b || usi == b) {
            printf("%d\n",count);
            return 0;
        }
        mae++;
        usi--;
        if (usi == -1) {
            usi = 9;
        }
        if (mae == 10) {
            mae = 0;
        }
        count++;
    }
}
    



