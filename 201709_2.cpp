#include <cstdio>
#include <algorithm>

using namespace std;

int key[1001];

struct teacher {
	int usingKey;
	int begin;
	int end;
} T1[1001], T2[1001];

bool cmp1(struct teacher a, struct teacher b) {
	return a.begin < b.begin;
}

bool cmp2(struct teacher a, struct teacher b) {
	return a.end < b.end;
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	// 将钥匙盒初始化
	for (int i = 1; i <= N; i++) {
		key[i] = i;
	} 
	// 输入各个老师使用钥匙的信息, 顺便计算最多到哪一个时刻 
	int maxTime = -1; // 记录最多到哪一个时刻 
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &T1[i].usingKey, &T1[i].begin, &T1[i].end);
		int tmp = T1[i].begin + T1[i].end;
		if (tmp > maxTime) {
			maxTime = tmp;
		}	
		T2[i] = T1[i];
	}
	sort(T1, T1 + K, cmp1); // 将老师们按使用钥匙的时间排序
	sort(T2, T2 + K, cmp2); // 将老师们按归还钥匙的时间排序 
	// 进行每一个时刻 
	return 0;
} 
