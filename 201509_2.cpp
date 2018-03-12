#include <cstdio>

int month[13][2] = {{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, 
	{30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

int main() {
	int y, d;
	scanf("%d%d", &y, &d);
	int yFlag = 0;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) yFlag = 1;
	int mm = 1, dd = 1, cnt = 1;
	while (cnt != d) {
		if (dd == month[mm][yFlag] && mm != 12) {
			dd = 0;
			mm++;
		}
		cnt++;
		dd++;
	}
	printf("%d\n%d\n", mm, dd);
	return 0;
}
