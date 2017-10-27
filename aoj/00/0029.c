#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[501][501];

int main(void)
{
    int i = 0, j, max = 0, count = 1;
    int words = 0;
    char many[33], longest[33]={0};

    while (scanf("%s",input[i]) != EOF) {
        words++;
//	printf("%s\n",input[i]);
//	strcpy(longest, input[i]);
//    for (j = 0; j < 33; j++) {
//        printf("%d ",input[j][i]);
//	}puts("");
//    for (j = 0; j < 33; j++) {
//        printf("%d ",longest[j]);
//    }puts("\n");
        if (max < strlen(input[i])) {
            strcpy(longest, input[i]);
            max = strlen(input[i]);
        }
        i++;
    }

    /*for (i = 0; i < words; i++) {
        printf("%s\n",input[i]);
    }*/

    max = 0;

    qsort(input, words, sizeof(char) * 501, strcmp);

for(i = 0;i < words;i++){
	printf("%s\n",input[i]);
}

    for (i = 0; i < words-1; i++) {
        if (!strcmp(input[i], input[i+1])) {
            count++;
        } else {
            if (max < count) {
                max = count;
                strcpy(many, input[i]);
            }
            count = 1;
        }
    }

/*    for (i = 0; i < 33; i++) {
        printf("%d ",longest[i]);
    }
*/
    printf("%s %s\n",many, longest);


    return 0;
}


