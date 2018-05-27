#include <cstdio>

bool out[1001]; // 建立哈希表, 记录每个小朋友的淘汰情况

int main() {
	int n, k;
	int outNum = 0; // 已淘汰的人数
	int cnt = 1; // 报的数
	int index = 0; // 当前报数的小朋友编号
	scanf("%d%d", &n, &k);
	// 初始化哈希表
	for (int i = 0; i < n; i++) {
		out[i] = false;
	}
	while (outNum != n - 1) { //剩下人数不止一人时, 一直循环下去
		if (cnt % k == 0 || cnt % 10 == k) {
			out[index] = true;
			outNum++;
		}
		cnt++;
		do {
			index = (index + 1) % n;
		} while (out[index] == true);
	} 
	int winNum;
	for (int i = 0; i < n; i++) {
		if (out[i] == false) {
			winNum = i + 1;
			break;
		} 
	}
	printf("%d\n", winNum);
	return 0;
}
