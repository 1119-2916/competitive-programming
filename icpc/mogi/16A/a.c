#include <stdio.h>

int main(void) {
	char a[3];
	int i, n, flag = 0, a_count = 0, b_count = 0;
	
	scanf("%d", &n);
	
	for(i = 0; i  < n; i++) {
		scanf("%s", a);
		if(a[0] == 'A') {
			a_count++;
		} else {
			b_count++;
		}
		if(b_count > a_count) {
			flag = 1;
			break;
		}
	}
	if(a_count != b_count || 2 * a_count != n) {
		flag = 1;
	}
	if(flag == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
