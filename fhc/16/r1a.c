#include <stdio.h>

#define MA_DATA 100000

int input[MAX_DATA];
int count, ans;
int t, contest, n;

int main(void)
{
    int i, j, before;

    scanf("%d",&t);

    for (contest = 1; contest <= n; contest++) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) {
            scanf("%d",&input[i]);
        }

        before = -1;
        count = 0;

        for (i = 0; i < n; i++) {
            if(before == -1) {
                before = input[i];
                count = 1;
            } else if(before > input[i]) {
                //
            } else if(before < input[i] && input[i] < before + 11) {
                count++;
                if (count == 4) {
                    count = 0;
                    before = -1;
                }
            } else if (input[i] < before + 21) {
                if (count == 












