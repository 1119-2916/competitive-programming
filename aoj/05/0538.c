#include <stdio.h>

int n, m;

int main(void)
{
    int i, j, len, bef, now;
    char tmp;
    scanf("%d %d",&n, &m);
    scanf("%c",&tmp);
    if (tmp == 'O') {
        bef = 1;
    } else {
        bef = -1;
    }
    while (scanf("%c",&tmp) != EOF) {
        if (tmp == 'O') {
            now = 1;
        } else {
            now = -1;
        }
        if (now*-1 == bef) {
            count++;
        } else {

        if (tmp == 'O') {
            bef = 1;
        } else {
            bef = -1;
        }


