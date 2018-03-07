#include <cstdio>

const int MAXN = 1000;
int a[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n - 2; i++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			cnt++;
			// printf("i=%d\n", i);
		} else if (a[i] < a[i + 1] && a[i] < a[i - 1]) {
			cnt++;
			// printf("i=%d\n", i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}
