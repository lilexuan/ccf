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
	for (int i = 1; i <= n; i++) {
		scanf("%d", &Ball[i].pos);
		Ball[i].speed = 1;
	}
	for (int i = 0; i < 1001; i++) {
		Line[i].ball1 = 0;
		Line[i].ball2 = 0; 
		Line[i].conflict = false;
	}
	for (int i = 1; i <= n; i++) {
		Line[Ball[i].pos].ball1 = i;
	}
	for (int u = 0; u < t; u++) {
		// 对每个小球进行移动
		for (int i = 1; i <= n; i++) {
			// 如果该球属于当前位置的球1或者0, 那么将其所在位置清零
			if (Line[Ball[i].pos].ball1 == i) {
				Line[Ball[i].pos].ball1 = 0;
				//Line[Ball[i].pos + Ball[i].speed].ball1 = i;
				Line[Ball[i].pos].conflict = false;
			} else if (Line[Ball[i].pos].ball2 == i) {
				Line[Ball[i].pos].ball2 = 0;
				//Line[Ball[i].pos + Ball[i].speed].ball2 == i;
				Line[Ball[i].pos].conflict = false;
			}
			// 移动该球
			Ball[i].pos += Ball[i].speed;
		}
		for (int i = 1; i <= n; i++) {
			// 对每个位置进行刷新
			if (Line[Ball[i].pos].ball1 == 0) {
				// 如果当前第一个球位是空的, 说明这个位置还没有球进来, 那么就是暂时没有冲突
				Line[Ball[i].pos].ball1 = i;
				Line[Ball[i].pos].conflict = false;
			} else {
				// 如果第一个球位不是空的, 那么说明有冲突
				Line[Ball[i].pos].ball2 = i;
				Line[Ball[i].pos].conflict = true;
				// 有冲突的话, 两个冲突的小球速度反向
				int tmp_pos = Line[Ball[i].pos].ball1;
				Ball[i].speed = -Ball[i].speed;
				Ball[tmp_pos].speed = -Ball[tmp_pos].speed;
			}
			// 如果球在边缘位置, 同样需要将速度反向
			if (Ball[i].pos == 0 || Ball[i].pos == L) {
				Ball[i].speed = -Ball[i].speed;
			}
		}
		// test
		/*
		for (int i = 1; i <= n; i++) {
			printf("ball%d's pos: %d\n", i, Ball[i].pos);
		}
		*/
	}
	for (int i = 0; i < n; i++) {
		if (i) {
			printf(" ");
		}
		printf("%d", Ball[i + 1].pos);
	}
	printf("\n");
	return 0;
}
