#include <cstdio>

int main() {
	char c1, c2, c3, c4, c5, c6, c7, c8, c9, id;
	scanf("%c-%c%c%c-%c%c%c%c%c-%c", &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &id);
	int num = (c1 - '0') * 1 + (c2 - '0') * 2 + (c3 - '0') * 3 + (c4 - '0') * 4 + (c5 - '0') * 5 + (c6 - '0') * 6 + (c7 - '0') * 7 + (c8 - '0') * 8 + (c9 - '0') * 9;
	//printf("num=%d\n", num);
	num = num % 11;
	//printf("num=%d\n", num);
	char cal_id;
	if (num == 10) {
		cal_id = 'X';
	} else {
		cal_id = num + '0';
	}
	if (cal_id == id) {
		printf("Right\n");
	} else {
		printf("%c-%c%c%c-%c%c%c%c%c-%c\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, cal_id);
	}
	return 0;
} 
