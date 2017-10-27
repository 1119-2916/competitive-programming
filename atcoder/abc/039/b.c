#include <stdio.h>
#include <string.h>

char input[27];
char data[41] = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBW";

int main(void)
{
    char *a;
    int i;
    scanf("%s", input);
    a = strstr(data, input);
    i = a - data;
    if (i == 0) {
        puts("Do");
    } else if (i == 2) {
        puts("Re");
    } else if (i == 4) {
        puts("Mi");
    } else if (i == 5) {
        puts("Fa");
    } else if (i == 7) {
        puts("So");
    } else if (i == 9) {
        puts("La");
    } else if (i == 11) {
        puts("Si");
    }
    return 0;
}
