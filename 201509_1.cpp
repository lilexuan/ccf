#include <cstdio>

const int MAXN = 1000;
int a[MAXN];

int main() {
	int n, cnt = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int i = 1;
	while (i < n) {
		while (a[i] == a[i - 1]) {
			i++;
		}
		if (i >= n) {
			break;
		} else {
			cnt++;
			i++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
