#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char numa[101], namb[101];
char ans[101];
int data, lena, lenb;

int main(void)
{
    int i, d, j, k;

    scanf("%d",&data);
    for (d = 0; d < data; d++) {
        scanf("%s %s", numa, numb);
        lena = strlen(numa);
        lenb = strlen(numb);
        i = lena-1;
        j = lenb-1;
        k = 0;
        while (i >= 0) {
            ans[k] += numa[i] + numa[j] - '0' - '0';
            ans[k+1] = ans[k] / 10;
            ans[k] %= 10;



