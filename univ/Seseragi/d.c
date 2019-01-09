#include <stdio.h>

int check[100];
int used[100];
int graph[100][100];
int line[100];
double nebo[100];
int n, t;
void hero(int i);

int main(void)
{
	int i, j, k, tmp;
	double ans, all;
	scanf("%d", &n);
	while (n) {
		for (i = 0; i < 100; i++) {
			check[i] = 0;
		}
		ans = 1.0;
		for (i = 0; i < n; i++) {
			scanf("%lf %d", &nebo[i], &k);
			for (j = 0; j < k; j++) {
					scanf("%d", &tmp);
					graph[i][tmp-1] = 1;
					check[tmp-1] = 1;
			}
		}
		for (i = 0; i < n; i++) {
			used[i] = 0;
			if (!check[i]) {
				ans *= (1-nebo[i]);
			}
		}
		for (i = 0; i < n; i++) {
		if (used[i]) {
			hero(i);
			all = 1.0;
			for (j = 0; j < n; j++) {
				if (used[j] == 1) {
					all *= nebo[line[j]];
				}
			}
			ans *= (1-all);
		}
		}
		//printf("%lf\n", ans);
/*		for (i = 0; i < n; i++) {
			t = 0;
			if (check[i] && !used[i]) {
				hero(i);
				if (t != 0) {
				all = 1.0;
				for (j = 0; j < t; j++) {
					all *= nebo[line[j]];
					printf("all:%lf\n",all);
				}
				ans *= (1-all);
				}
			}
		}*/
	
		printf("%lf\n", ans);
		scanf("%d", &n);
	}
	
	return 0;
}

void hero(int i)
{
	int j, fl;
	fl = 0;
	for (j = 0; j < n; j++) {
		if (graph[i][j]) {
				used[j]++;
				fl = 1;
		}
	}
	if (!fl) {
		used[i] = -4;
	}
}	

