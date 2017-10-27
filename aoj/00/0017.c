#include <stdio.h>
#include <string.h>

char input[81];
char tmp[81];
char the[6] = " the ";
char the1[6] = " the.";
char this1[7] = " this.";
char that1[7] = " that.";
char this[7] = " this ";
char that[7] = " that ";
char the2[5] = "the ";
char this2[6] = "this ";
char that2[6] = "that ";
char the3[5] = "the";
char this3[6] = "this";
char that3[6] = "that";

int str_(char a[], char b[], int n);

int main(void)
{
    int i, j, k, n, ans, length, input_length;


    while (fgets(input, 10000, stdin) != NULL) {
        input_length = strlen(input);

        while (1) {
            if (str_(input+input_length-4, the3, 4)) {
                break;
            }
            if (str_(input+input_length-5, this3, 5)) {
                break;
            }
            if (str_(input+input_length-5, that3, 5)) {
                break;
            }
            if (str_(input, the2, 4)) {
                break;
            }
            if (str_(input, this2, 5)) {
                break;
            }
            if (str_(input, that2, 5)) {
                break;
            }
            if (strstr(input, the) != NULL) {
                break;
            }
            if (strstr(input, this) != NULL) {
                break;
            }
            if (strstr(input, that) != NULL) {
                break;
            }
            if (strstr(input, the1) != NULL) {
                break;
            }
            if (strstr(input, this1) != NULL) {
                break;
            }
            if (strstr(input, that1) != NULL) {
                break;
            }
            i = 0;
            while (i < input_length) {
                if (input[i] == 'z') {
                    input[i] = 'a';
                } else if (input[i] == ' ' || input[i] == '.') {
                    ;
                } else {
                    input[i]++;
                }
                i++;
            }
            //printf("%s",input);
        }
        printf("%s\n",input);
    }
    return 0;
}

int str_(char a[], char b[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        } 
    }
    return 1;
}





