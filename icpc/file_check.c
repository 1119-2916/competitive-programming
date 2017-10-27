#include <stdio.h>
#include <string.h>

int file_check_same(char *file_name_01, char *file_name_02);
void file_assist(char *file_name);

int main(void)
{
    char f_name_ans[30], f_name_output[30];
    int ret_num;

    printf("input collect answer file name : ");
    scanf("%s",f_name_ans);

    printf("input your answer file name : ");
    scanf("%s",f_name_output);

    file_assist(f_name_ans);
    file_assist(f_name_output);

    ret_num = file_check_same(f_name_ans, f_name_output);

    if (ret_num == 1) {
        puts("Accepted!!");
    } else if (ret_num == 0) {
        puts("Failed");
    } else {
        puts("ERROR");
    }

    return 0;
}

void file_assist(char *file_name)
{
    char *extension = ".txt";
    int i, file_name_length;

    file_name_length = strlen(file_name);

    for (i = 0; i < file_name_length; i++) {
        if (file_name[i] == '.') {
            break;
        }
    }

    if (i == file_name_length) {
        file_name = strcat(file_name, extension);
    }
}

int file_check_same(char *file_name_01, char *file_name_02)
{
    FILE *fp_01, *fp_02;
    int ret_num_01, ret_num_02, count_input_line = 0, wrong_answer = 0;
    char file_data_01[500], file_data_02[500];

    fp_01 = fopen(file_name_01, "r");
    if (fp_01 == NULL) {
        printf("You can not open the file \"%s\".\n", file_name_01);
        return -1;
    }

    fp_02 = fopen(file_name_02, "r");
    if (fp_02 == NULL) {
        printf("You can not open the file \"%s\".\n", file_name_02);
        return -1;
    }

    while (1) {
        ret_num_01 = fscanf(fp_01, "%s", file_data_01);
        ret_num_02 = fscanf(fp_02, "%s", file_data_02);

        if (ret_num_01 == EOF && ret_num_02 == EOF) {
            break;
        } else if(ret_num_01 == EOF) {
            puts("Too long answer");
            return 0;
        } else if(ret_num_02 == EOF) {
            puts("Too short answer");
            return 0;
        }
        count_input_line++;

        if (strcmp(file_data_01, file_data_02)) {
            printf("Line %d input is wrong.\n", count_input_line);
            wrong_answer = 1;
        }
    }
    if (wrong_answer) {
        return 0;
    } else {
        return 1;
    }
}

















    
