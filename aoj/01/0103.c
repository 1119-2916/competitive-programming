#include <stdio.h>
#include <string.h>


int main(void) {
    char hit[4] = "HIT";
    char out[4] = "OUT";
    char hom[8] = "HOMERUN";
    char inp[10];
    int n, point = 0, out_count = 0, rui = 0, i;
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        while(out_count != 3) {
            scanf("%s",inp);
            if(!strcmp(inp, hit)) {
                rui++;
                if(rui == 4) {
                    point++;
                    rui--;
                }
            } else if(!strcmp(inp, hom)) {
                point += 1 + rui;
                rui = 0;
            } else if(!strcmp(inp, out)) {
                out_count++;
            }
        }
        printf("%d\n",point);
        point = 0;
        out_count = 0;
        rui = 0;
    }
}

