#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int num;
    struct node *hidari, *migi;
};

char input_a[1001];
char input_b[1001];
int length, pos;

struct node *make_tree(char data[], int len);
void print_tree(struct node *tree);
void make_next(struct node *a, struct node *b);

struct node *top_a, *top_b, *top_c;

int main(void)
{
    int i, j;
    scanf("%s",input_a);
    length = strlen(input_a);
    pos = 0;
    top_a = make_tree(input_a, length);
    //print_tree(top_a);

    scanf("%s",input_b);
    length = strlen(input_b);
    pos = 0;
    top_b = make_tree(input_b, length);
    //print_tree(top_b);

    make_next(top_a, top_b);
    puts("");

    return 0;

}
struct node *make_tree(char data[], int len) 
{
    struct node *now;
    now = (struct node*)malloc(sizeof(struct node));
    now->num = -1;
    now->hidari = NULL;
    now->migi = NULL;
    int fl = 0;
    while (pos < len) {
        if (data[pos] == '(') {
            if (fl == 0) {
                pos++;
                now->hidari = make_tree(data, len);
            } else {
                pos++;
                now->migi = make_tree(data, len);
            }
        } else if (data[pos] == '[') {
            pos++;
            now->num = 0;
            while (1) {
                if (data[pos] != ']') {
                    now->num *= 10;
                    now->num += data[pos] - '0';
                    pos++;
                } else {
                    break;
                }
            }
            pos += 1;
            fl = 1;
        } else if (data[pos] == ')') {
            pos++;
            return now;
        }
    }
    return now;
}

void print_tree(struct node *tree) 
{
    if (tree->hidari != NULL) {
        if (tree->hidari->num == -1) {
            printf("()");
        } else {
            printf("(");
            print_tree(tree->hidari);
            printf(")");
        }
    }
    printf("[%d]",tree->num);
    if (tree->migi != NULL) {
        if (tree->migi->num == -1) {
            printf("()");
        } else {
            printf("(");
            print_tree(tree->migi);
            printf(")");
        }
    }
    return ;
}

void make_next(struct node *a, struct node *b) 
{
    if (a->hidari != NULL && b->hidari != NULL) {
        if (a->hidari->num == -1 || b->hidari->num == -1) {
            printf("()");
        } else {
            printf("(");
            make_next(a->hidari, b->hidari);
            printf(")");
        }
    }
    printf("[%d]",a->num+b->num);
    if (a->migi != NULL && b->migi != NULL) {
        if (a->migi->num == -1 || b->migi->num == -1) {
            printf("()");
        } else {
            printf("(");
            make_next(a->migi, b->migi);
            printf(")");
        }
    }
}


