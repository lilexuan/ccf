#include <cstdio>

int main() {
	int n; 
	scanf("%d", &n);
	int num_of_50 = 0, num_of_30 = 0, num_of_10;
	num_of_50 = n / 50;
	num_of_30 = (n - num_of_50 * 50) / 30;
	num_of_10 = (n - num_of_50 * 50 - num_of_30 * 30) / 10;
	int sum = 7 * num_of_50 + 4 * num_of_30 + num_of_10;
	printf("%d", sum);
	return 0;
}
