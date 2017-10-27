#include <stdio.h>

int n, w, fin;
int iv[200];
int iw[200];

long long int tmp;
struct pair _tmp;

void solve1(void);
void solve2(void);
void solve3(void);
long long int max(long long int a, long long int b);
long long int min(long long int a, long long int b);

typedef struct pair{
    long long int v;
    long long int w;
} pair;

int main(void) 
{
    int i, f2= 0, f3 = 0;

    scanf("%d %d",&n, &w);

    for (i = 0; i < n; i++) {

        scanf("%d %d",&iv[i], &iw[i]);

        if (iv[i] > 1000) {

            f3 = 1;

        }

    }

    if (n <= 30) {

        solve1();

    } else if (f3) {

        solve2();

    } else {

        solve3();

    }

    return 0;

}

void solve1(void)
{
    int mev_1[32800];
    int mev_2[32800];
    int mev_m[32800];

    int mew_1[32800];
    int mew_2[32800];
    int mew_m[32800];
 
    int n2 = n / 2;

    for (int i = 0; i < 1 << n2; i++) {




    // 半分ずつ全探して結果をうまくマージする最強のソースコード

}

long long int rec(int n, int w) 
{
    long long int tmp;
    if (n == fin) {
        tmp = 0;
    } else if (w < a[n]) {
        tmp = 0;
    } else {
        tmp = max(rec(n+1, w), rec(n+1, w - iw[n]) + iv[n]);
    } return tmp;
}


void solve2(void) 
{
    int i, j;
    long long int dp[200000] = {0}, ans = 0;
    for (i = 0; i < n; i++) {
        if (iw[i] <= w) {
            for (j = 200000 - 1; j > 0; j--) {
                if (dp[j] && j + iw[i] <= w) {
                    dp[j + iw[i]] = max(dp[j] + iv[i], dp[j + iw[i]]);
                }
            }
            dp[0 + iw[i]] = max(dp[0] + iv[i], dp[0 + iw[i]]);
        }
    }
    for (i = 0; i < 200000; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    printf("%lld\n",ans);
}

void solve3(void)
{
    int i, j;
    long long int dp[200000] = {0}, ans = 0, tmp = 1000000000;
    tmp *= 200;
    tmp++;
    for (i = 1; i < 200000; i++) {
        dp[i] = tmp;
    }
    for (i = 0; i < n; i++) {
        for (j = 200000-1; j >= 0; j--) {
            if (dp[j] != tmp) {
                dp[j + iv[i]] = min(dp[j+iv[i]],dp[j]+iw[i]);
            }
        }
    }
    for (i = 200000-1; i >= 0; i--) {
        if (dp[i] <= w) {
            printf("%d\n",i);
            break;
        }
    }
}

long long int max(long long int a, long long int b)
{
    if (a < b) {
        return b;
    } else {
        return a;
    }
}

long long int min(long long int a, long long int b)
{
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int pow_int(int a) 
{
    if (a == 0) {
        return 1;
    } 
    return a * pow_int(a-1);
}

