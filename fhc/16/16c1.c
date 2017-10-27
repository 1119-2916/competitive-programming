#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUT_NUMBER 1000000000
#define MAX_INPUT_DATA 100000
#define MAX_DATASET 40

int data_set[MAX_INPUT_DATA];
int t, p, n, count, sum;

int main(void) 
{
    int data_case, i, j, syaku;
    unsigned int tmp;
    scanf("%d",&t);
    for (data_case = 1; data_case <= t; data_case++) {
        count = 0;
        scanf("%d %d",&n, &p);
        for (i = 0; i < n; i++) {
            scanf("%d",&data_set[i]);
            if(data_set[i] <= p) {
                count++;
            }
        }

        syaku = 0;
        sum = 0;
        for (i = 0; i < n; i++) {










