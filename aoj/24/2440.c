#include <stdio.h>
#include <string.h>

char ok[256][11];
int n, m;

int main(void)
{
    int i, j, now = 0, fl;
    char input[11];
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%s",ok[i]);
    }
    scanf("%d",&m);
    for (i = 0; i < m; i++) {
        scanf("%s",input);
        fl = 0;
        for (j = 0; j < n; j++) {
            if (strcmp(input, ok[j]) == 0) {
                fl = 1;
                break;
            }
        }
        if (fl) {
            if (now) {
                printf("Closed by %s\n",input);
                now = 0;
            } else {
                printf("Opened by %s\n",input);
                now = 1;
            }
        } else {
            printf("Unknown %s\n",input);
        }
    }
    return 0;
}
            
