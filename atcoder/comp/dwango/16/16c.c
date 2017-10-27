#include <stdio.h>
#include <stdlib.h>

#define MAX_EKI 25252

struct eki {
    int num;
    struct eki *next;
    int next_time;
};

struct eki *rosen[MAX_EKI];
struct eki *node;

int n, m, src, dst, ans;

int main(void)
{
    int i, j, k, tmp, eki_num;
    scanf("%d %d %d %d",&n, &m, &src, &dst);

    for (i = 0; i < m; i++) {
        scanf("%d",&eki_num);
        rosen[i] = mklist(eki_num);
    }
}

struct eki *mklist(int eki_num)
{
    int eki_name[MAX_EKI];
    int i;

    for (i = 0; i < eki_num; i++) {
        scanf("%d",&eki_name[i]);


struct eki *mklist(int eki_count)
{
    struct eki *sentou;
    sentou = (struct eki *)malloc(sizeof(struct eki));
    scanf("%d",&tmp);
    sentou->num = tmp;
    if (eki_count > 1) {

    }
    return sentou;
}

void append(struct eki *now, int num) 
{
    struct eki *app;
    int tmp;
    if (!num) {
        return;
    }
    app = (struct eki *)malloc(sizeof(struct eki));
    scanf("%d",&tmp);
    app->num = tmp;
    now->next = app;
    now->







       


