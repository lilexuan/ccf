#include <cstdio>

int main() {
	int num;
	int sum = 0;
	int cnt = 0;
	while (scanf("%d", &num) != EOF) {
		if (num == 0) {
			break;
		}
		if (num == 2) {
			cnt += 1;
		}
		if (num == 1) {
			cnt = 0;
		}
		if (cnt == 0) {
			sum += 1;
		} else {
			sum += 2 * cnt;
		}
	}
	printf("%d\n", sum);
	return 0;
}