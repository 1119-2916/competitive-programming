#include <stdio.h>
#define MAX_B 40001
#define delt 20000

int board[40001][40001];
int point[100][2];
int n;

void make(void);

int main(void)
{
	int i, j, k, x, y;
	scanf("%d", &n);
	while (n) {
		for (i = 0; i < n; i++) {
			scanf("%d %d", &point[i][0], &point[i][1]);
			point[i][0] += delt;
			point[i][1] += delt;
			
		}
		puts("scaned");
		make();
		for (i = -delt; i < 10; i++) {
			for (j = -delt; j < 10; j++) {
				printf("%d ", board[i][j]);
			}
			puts("");
		}
	}
}

void make(void)
{
	int i, j;
	for (i = 0; i < MAX_B; i++) {
		for (j = 0; j < MAX_B; j++) {
			board[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++) {
		if (point[i][0] == point[(i+1)%n][0]) {
			if (point[i][1] < point[(i+1)%n][1]) {
				for (j = point[i][1]; j <= point[(i+1)%n][1]; j++) {
					board[point[i][1]][j] = 1;
				}
			} else {
				for (j = point[(i+1)%n][1]; j <= point[i][1]; j++) {
					board[point[i][1]][j] = 1;
				}
			}
		} else {
			if (point[i][0] < point[(i+1)%n][0]) {
				for (j = point[i][0]; j <= point[(i+1)%n][0]; j++) {
					board[j][point[i][0]] = 1;
				}
			} else {
				for (j = point[(i+1)%n][0]; j <= point[i][0]; j++) {
					board[j][point[i][0]] = 1;
				}
			}
		}
	}
}
	
			
