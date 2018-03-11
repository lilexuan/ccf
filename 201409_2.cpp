#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int a[101][101];
	fill(a[0], a[0] + 101 * 101, 0); // 二维数组初始化 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int j = x1; j < x2; j++) { // 不能等于....超级坑这里 
			for (int k = y1; k < y2; k++) {
				a[j][k] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (a[i][j] == 1) {
				cnt++;
			}
		}
	}
	/*
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d\n", cnt);
	return 0;
}
