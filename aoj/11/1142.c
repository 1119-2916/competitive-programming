#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

char input[N], a[N-1], b[N-1], a_[N-1], b_[N-1], tmp_string[N];
char ans[504][504];
int push_count;

int cmp_char_my(void *a, void *b);
void reverce(char moto[], char ato[], int len);
void reset_array(char str[]);
void strappend(char mae[], char ato[], char tmp_string[]);
void push(char push_string_data[]);
void sort(int size);
void reset(void);

int main(void)
{
    int i, j, data, k, length, answer;
    scanf("%d",&data);
    for (k = 0; k < data; k++) {
        reset();
        answer = 1;
        scanf("%s",input);
        length = strlen(input);
        push(input);
        push_count = 1;
        for (i = 1; i < length; i++) {

            reset_array(a);
            reset_array(b);
            reset_array(a_);
            reset_array(b_);

            strncpy(a, input, sizeof(char)*i);
            reverce(a, a_, i);
            strncpy(b, &input[i], sizeof(char)*(length-i));
            reverce(b, b_, length-i);

            strappend(b, a, tmp_string);
            push(tmp_string);

            strappend(a_, b, tmp_string);
            push(tmp_string);

            strappend(b, a_, tmp_string);
            push(tmp_string);

            strappend(a, b_, tmp_string);
            push(tmp_string);

            strappend(b_, a, tmp_string);
            push(tmp_string);

            strappend(a_, b_, tmp_string);
            push(tmp_string);

            strappend(b_, a_, tmp_string);
            push(tmp_string);
            //printf("%s\n%s\n%s\n%s\n", a, b, a_, b_);
        }
        sort((length-1)*7+1);
        for (i = 1; i < (length-1)*7 + 1; i++) {
            if (strcmp(ans[i-1], ans[i])) {
                answer++;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}

void push(char push_string_data[])
{
    int i;
    strcpy(ans[push_count], push_string_data);
    //printf("%s\n",ans[push_count]);
    push_count++;
}
void strappend(char mae[], char ato[], char tmp_string[])
{
    int i, len_mae, len_ato;
    len_mae = strlen(mae);
    len_ato = strlen(ato);
    for (i = 0; i < len_mae; i++) {
        tmp_string[i] = mae[i];
    } 
    for (i = 0; i < len_ato; i++) {
        tmp_string[len_mae + i] = ato[i];
    }
    tmp_string[len_mae + len_ato] = '\0';
}

void reset_array(char str[]) 
{
    int i;
    for (i = 0; i < N-1; i++) {
        str[i] = '\0';
    }
}

void reverce(char moto[], char ato[], int len)
{
    int i, j;
    for (i = 0; i < len; i++) {
        ato[i] = moto[len-i-1];
    }
    ato[len] = '\0';
}

void sort(int size)
{
    int i, j;
    char tmp[N];
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (cmp_char_my(&ans[j], &ans[j+1]) > 0) {
                strcpy(tmp, ans[j]);
                strcpy(ans[j], ans[j+1]);
                strcpy(ans[j+1], tmp);
            }
        }
    }
}

int cmp_char_my(void *a, void *b) 
{
    int i, j;
    char *ta, *tb;
    ta = a;
    tb = b;
    for (i = 0; i < N; i++) {
        if (ta[i] != tb[i]) {
            return ta[i] - tb[i];
        }
    }
    return 0;
}

void reset(void)
{
    int i, j;
    for (i = 0; i < 504; i++) {
        for (j = 0; j < 504; j++) {
            ans[i][j] = 0;
        }
    }
    push_count = 0;
}

