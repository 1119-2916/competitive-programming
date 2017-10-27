#include <stdio.h>

long long int ans, n, j;

int main(void)
{
    int i, depth = 0;

    scanf("%lld",&n);

    ans = 1;

    for (j = n; j > 0; j /= 2) {
        depth++;
    }
    if (depth % 2) {
        for (i = 0;; i++) {
            if (ans > n) {
                break;
            }
            if (i % 2) {
                ans *= 2;
            } else {
                ans = ans * 2 + 1;
            }
        }
        if (i % 2) {
            puts("Takahashi");
        } else {
            puts("Aoki");
        }
    } else {
        for (i = 0;; i++) {
            if (ans > n) {
                break;
            }
            if (i % 2) {
                ans = ans * 2 + 1;
            } else {
                ans *= 2;
            }
        }
        if (i % 2) {
            puts("Aoki");
        } else {
            puts("Takahashi");
        }
    }

        return 0;
    }





