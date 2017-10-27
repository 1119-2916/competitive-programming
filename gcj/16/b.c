#include <stdio.h>
#include <string.h>
#define LEN 100

char input[LEN];
int tower[LEN];
int catch[LEN];
int height;
int t;

void make_tower(void);
int bot_search(void);
int top_search(void);

int main(void)
{
    int i, j, k, top, bot, count;
    scanf("%d",&t);
    for (i = 1; i <= t; i++) {
        count = 0;
        scanf("%s",input);
        printf("Case #%d: ",i);
        make_tower();

        while (1) {
            top = top_search();
            if (top == height) {
                break;
            }
            if (top) {
                for (j = 0; j < top; j++) {
                    catch[j] = tower[j] * -1;
                }
                for (j = 0; j < top; j++) {
                    tower[j] = catch[top-j-1];
                }
                count++;
            }
            bot = bot_search();
            for (j = bot; j >= 0; j--) {
                    catch[j] = tower[j] * -1;
                }
            for (j = bot; j >= 0; j--) {
                tower[j] = catch[bot-j];
            }
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}

void make_tower(void)
{
    int i, len;
    len = strlen(input);
    height = len;
    for (i = 0; i < len; i++) {
        if (input[i] == '+') {
            tower[i] = 1;
        } else if (input[i] == '-') {
            tower[i] = -1;
        } else {
            printf("input error\n");
            return;
        }
    }
}

int top_search(void)
{
    int i, j;
    for (i = 0; i < height; i++) {
        if (tower[i] == -1) {
            return i;
        }
    }
    return i;
}

int bot_search(void)
{
    int i;
    for (i = height-1; i >= 0; i--) {
        if (tower[i] == -1) { 
            return i;
        }
    }
}

