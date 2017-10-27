#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 1010001000
#define min(a, b) a>b?b:a
#define max(a, b) a>b?a:b

typedef struct st{
    int be, af;
}st;

st data[121];
char str[9];

int main(void)
{
    int a, b, c, d, e, f, g, h, i, j, k, n, m;
    long long int ans = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &data[i].be, &data[i].af);
    }
    for (a = 1; a < 9; a++) {
        str[a] = 'a';

        for (b = 1; b < 9; b++) {
            if (a == b) continue;
            str[b] = 'b';

            for (c = 1; c < 9; c++) {
                if (a == c) continue;
                if (b == c) continue;
            str[c] = 'c';

                for (d = 1; d < 9; d++) {
                    if (a == d) continue;
                    if (b == d) continue;
                    if (c == d) continue;
            str[d] = 'd';

                    for (e = 1; e < 9; e++) {
                        if (a == e) continue;
                        if (b == e) continue;
                        if (c == e) continue;
                        if (d == e) continue;

            str[e] = 'e';
                        for (f = 1; f < 9; f++) {
                            if (a == f) continue;
                            if (b == f) continue;
                            if (c == f) continue;
                            if (d == f) continue;
                            if (e == f) continue;

            str[f] = 'f';
                            for (g = 1; g < 9; g++) {
                                if (a == g) continue;
                                if (b == g) continue;
                                if (c == g) continue;
                                if (d == g) continue;
                                if (e == g) continue;
                                if (f == g) continue;

            str[g] = 'g';
                                for (h = 1; h < 9; h++) {
                                    if (a == h) continue;
                                    if (b == h) continue;
                                    if (c == h) continue;
                                    if (d == h) continue;
                                    if (e == h) continue;
                                    if (f == h) continue;
                                    if (g == h) continue;
            str[h] = 'h';
            fl = 0;
    for (i = 0; i < m; i++) {
        if (str['a' - 1 + data[i].be] < 



                                    return 0;
                                }
