#include <stdio.h>

int main(void)
{
	int r, w, c, n;
	scanf("%d %d %d %d",&r, &w, &c, &n);
	while(w) {
        int a = c * w - r;
	if (a <= 0) {
		printf("0\n");
	} else {		
        if (a % n) {
            printf("%d\n", a/n+1);
        } else {
            printf("%d\n", a/n);
        }
}
     	scanf("%d %d %d %d",&r, &w, &c, &n);
    }
    return 0;
}   
		

