#include <stdio.h>

int dir, dis;

int main(void)
{
    int i;
    scanf("%d %d",&dir, &dis);

    if (dis <= 14) {
        dis = 0;
    } else if (dis <= 92) {
        dis = 1;
    } else if (dis <= 200) {
        dis = 2;
    } else if (dis <= 326) {
        dis = 3;
    } else if (dis <= 476) {
        dis = 4;
    } else if (dis <= 644) {
        dis = 5;
    } else if (dis <= 830) {
        dis = 6;
    } else if (dis <= 1028) {
        dis = 7;
    } else if (dis <= 1244) {
        dis = 8;
    } else if (dis <= 1466) {
        dis = 9;
    } else if (dis <= 1706) {
        dis = 10;
    } else if (dis <= 1958) {
        dis = 11;
    } else {
        dis = 12;
    }

    if (!dis) {
        puts("C 0");
    } else if (dir <= 112) {
        printf("N %d\n",dis);
    } else if (dir <= 337) {
        printf("NNE %d\n",dis);
    } else if (dir <= 562) {
        printf("NE %d\n",dis);
    } else if (dir <= 787) {
        printf("ENE %d\n",dis);
    } else if (dir <= 1012) {
        printf("E %d\n",dis);
    } else if (dir <= 1237) {
        printf("ESE %d\n",dis);
    } else if (dir <= 1462) {
        printf("SE %d\n",dis);
    } else if (dir <= 1687) {
        printf("SSE %d\n",dis);
    } else if (dir <= 1912) {
        printf("S %d\n",dis);
    } else if (dir <= 2137) {
        printf("SSW %d\n",dis);
    } else if (dir <= 2362) {
        printf("SW %d\n",dis);
    } else if (dir <= 2587) {
        printf("WSW %d\n",dis);
    } else if (dir <= 2812) {
        printf("W %d\n",dis);
    } else if (dir <= 3037) {
        printf("WNW %d\n",dis);
    } else if (dir <= 3262) {
        printf("NW %d\n",dis);
    } else if (dir <= 3487) {
        printf("NNW %d\n",dis);
    } else {
        printf("N %d\n",dis);
    }
    return 0;
}



