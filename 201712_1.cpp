#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int a[MAXN];

int cmp(int a, int b) {
	return a < b;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n, cmp);
	int MIN = 10001;
	for (int i = 1; i < n; i++) {
		int dif = a[i] - a[i - 1];
		if (dif < MIN) {
			MIN = dif;
		}
	}
	printf("%d\n", MIN);
	return 0;
}
