#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cell{
    int level;
    char word;
    struct cell *mother;
    struct cell *child[30];
    int count;
};

struct cell *add(char inp[], struct cell *now);
int calc(struct cell *now);

int main(void) {
    int n, i;
    char inp[30];
    struct cell node;
    struct cell *now;
    scanf("%d",&n);
    while(n) {
        scanf("%s",inp);
        node.level = 1;
        node.word = inp[0];
        node.mother = NULL;
        node.count = 0;
        now = &node;
        for(i = 1; i < n; i++) {
            scanf("%s",inp);
            now = add(inp, now);
        }
        printf("%d\n",calc(&node));
        scanf("%d",&n);
    }
    return 0;
}

struct cell *add(char inp[], struct cell *now) {
    int len;
    struct cell *new_one;
    new_one = (struct cell *)malloc(sizeof(struct cell));
    len = strlen(inp);
    while(now->level+1 != len) {
        now = now->mother;
    }
    new_one->level = now->level+1;
    new_one->word = inp[len-1];
    new_one->mother = now;
    now->child[now->count] = new_one;
    now->count++;
    return new_one;
}

int calc(struct cell *now) {
    int i, ans = 0;
    if(now->word == '+') {
        for(i = 0; i < now->count; i++) {
            ans += calc(now->child[i]);
        }
    } else if(now->word == '*') {
        ans = 1;
        for(i = 0; i < now->count; i++) {
            ans *= calc(now->child[i]);
        }
    } else {
        return (now->word - '0' );
    }
    return ans;
}

