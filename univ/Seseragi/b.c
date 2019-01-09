#include <stdio.h>
#include <string.h>

char input[200];
int board[9][9];
int n = 0, m = 0, max_m;

void make(void);
void print(void);

int main(void)
{
	int i, j, a, b, c, d;
	scanf("%s", input);
	while (input[0] != '#') {

for (i =0 ; i < 9 ;i++) {
for (j =0 ; j < 9; j++) {
board[i][j] = 0;
}
}
		make();

		//printf("%d %d\n", n, max_m);
		scanf("%d %d %d %d", &a, &b, &c, &d);
		board[a-1][b-1] = 0;
		board[c-1][d-1] = 1;

/*for (i =0 ; i < 9 ;i++) {
for (j =0 ; j < 9; j++) {
printf("%d ", board[i][j]);
}puts("");
}*/

		print();
		scanf("%s", input);
		puts("");
	}
	return 0;
}

void print(void)
{
	int i, j, add;
	for (i = 0; i <= n; i++) {
		for (j = 0; j < max_m; j++) {
			if (board[i][j] == 1) {
				printf("b");
			} else {
				add = 0;
				while (j < max_m && board[i][j] == 0) {
					add++;
					j++;
				}
				printf("%d", add);
				j--;
			}
		}
		if (i < n) printf("/");
	}
}
			
	

void make(void)
{
	int i = 0, len, j;
	max_m = 0;
	n = 0;
	m = 0;
	len = strlen(input);
	while (i < len) {
		if (input[i] == 'b') {
			board[n][m] = 1;
			m++;
			i++;
		} else if (input[i] == '/') {
			n++;
			if (max_m < m) {
				max_m = m;
			}
			m = 0;
			i++;
		} else {
			//printf("%d\n", input[i] - '0');
			for (j = 0; j < (input[i] - '0'); j++) {
				board[n][m++] = 0;
			}
			i++;
		}
	}
}
			
			
		
