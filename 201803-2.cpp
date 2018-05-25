#include <cstdio>

struct ball { // 球的结构体数组 
	int pos;
	int speed; // 1是向右, -1是向左
} Ball[101];

struct line { // 线段的结构体数组, 每一个位置是一个结构体
	int ball1, ball2;
	bool conflict;
} Line[1001];

int main() {
	int n, L, t;
	scanf("%d%d%d", &n, &L, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d", &Ball[i].pos);
		Ball[i].speed = 1;
	}
	for (int i = 0; i < 1001; i++) {
		Line[i].ball1 = 0;
		Line[i].ball2 = 0; 
		Line[i].conflict = false;
	}
	for (int i = 0; i < n; i++) {
		Line[Ball[i].pos].ball1 = i;
	}
	for (int i = 0; i < t; i++) {
		
	}
	return 0;
}