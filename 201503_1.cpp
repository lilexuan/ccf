#include <cstdio>
#define N 1000

int a[N][N]; // 以后要这样提前定义好数组..... 

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			scanf("%d", &num);
			a[i][j] = num;
		}
	}
	for (j = m - 1; j >= 0; j--) {
		for (i = 0; i < n; i++) {
			if (i != 0) { // ccf好像要写成 i != 0 
				printf(" ");
			}
			printf("%d", a[i][j]);
			//printf("%d(i = %d, j = %d)", a[i][j], i, j);
		}
		printf("\n");
	}
	return 0;
}
