#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char input[100001];

int main(void)
{
    int a, b, i, j, k, length;

    scanf("%s %d", input, &k);

    length = strlen(input);

    for (i = 0; i < length; i++) {
        if (input[i] == 'a' || ('z' + 1) - input[i] > k) {
            continue;
        } else {
            k -= ('z' + 1) - input[i];
            input[i] = 'a';
        }
    }
    k %= 26;
    input[i-1] += k;
    if (input[i-1] > 'z') {
        input[i-1] = input[i-1] - 'z' + 'a';
    }

    printf("%s\n", input);

    return 0;
}
