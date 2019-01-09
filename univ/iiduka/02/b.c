#include <stdio.h>
#include <string.h>

char rot[4] = "ROT";
char mov[4] = "MOV";
char rep[4] = "REP";
char end[4] = "END";
char tmp[4];
int num;
int x, y, f;

int main(void)
{
    scanf("%s",tmp);

    while (strcmp(tmp, end)) {
        if (!strcmp(tmp, rot)) {
        scanf("%d",&num);
            if (num >= 0) {
                f = ((num % 4) + f ) % 4;
            } else {
                num += 256;
                f = ((num % 4) + f ) % 4;
            }
        } else if (!strcmp(tmp,mov)) {
        scanf("%d",&num);
            if (!f) {
                x += num;
            } else if (f == 1) {
                y += num;
            } else if (f == 2) {
                x -= num;
            } else if (f == 3) {
                y -= num;
            }
        } else if (!strcmp(tmp,rep)) {
            printf("%d %d %d\n",x, y, f);
        }
        scanf("%s",tmp);
    }
    return 0;
}



