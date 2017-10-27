#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LEN 1001

int dp[MAX_INPUT_LEN][MAX_INPUT_LEN];
char s1[MAX_INPUT_LEN];
char s2[MAX_INPUT_LEN];
int len1, len2;

int min(int a, int b);

int main(void)
{
    int i, j, tmp;

    scanf("%s %s",s1, s2);
    len1 = strlen(s1);
    len2 = strlen(s2);

    for (i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }

    for (i = 0; i <= len2; i++) {
        dp[0][i] = i;
    }
        
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            tmp = (s1[i-1] == s2[j-1]) ? 0:1;
            dp[i][j] = min(dp[i-1][j-1]+tmp, 
                    min(dp[i-1][j]+1, dp[i][j-1]+1));
        }
    }

    printf("%d\n",dp[len1][len2]);

    return 0;
}

int min(int a, int b) 
{
    if (a > b) {
        return b;
    } else {
        return a;
    }
}



