#include <stdio.h>

char junban[24][5] = {"1234","1243","1324","1342",
                      "1423","1432","2134","2143",
                      "2314","2341","2413","2431",
                      "3124","3142","3214","3241",
                      "3412","3421","4123","4132",
                      "4213","4231","4312","4321"};
int x_base[4] = { 0, 1, 0,-1};
int y_base[4] = {-1, 0, 1, 0};
int x[4];
int y[4];

void make_x_y(int n);

int main(void)
{
    int i;
    for (i = 0; i < 24; i++) {
        puts("");
        make_x_y(i);
    }
    return 0;
}

void make_x_y(int n) 
{
    int i;
    for (i = 0; i < 4; i++) {
        x[i] = x_base[junban[n][i]-'1'];
        y[i] = y_base[junban[n][i]-'1'];
        printf("(%d,%d)\n",x[i], y[i]);
    }
}
    
