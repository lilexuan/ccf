#include <cstdio>
#include <algorithm>

using namespace std;

int key[1001]; // 钥匙盒, 记录每个位置上的钥匙号码 
int pos[1001]; // 哈希表, 记录钥匙在盒子上的位置 

struct teacher {
	int usingKey;
	int begin;
	int end;
} T1[1001], T2[1001];

bool cmp1(struct teacher a, struct teacher b) {
	return a.begin < b.begin;
}

bool cmp2(struct teacher a, struct teacher b) {
	if (a.end != b.end) {
		return a.end < b.end;
	} else {
		return a.usingKey < b.usingKey;
	}
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	// 将钥匙盒和哈希表初始化
	for (int i = 1; i <= N; i++) {
		key[i] = i;
		pos[i] = i;
	} 
	// 输入各个老师使用钥匙的信息, 顺便计算最多到哪一个时刻 
	int maxTime = -1; // 记录最多到哪一个时刻 
	for (int i = 0; i < K; i++) {
		int tmp;
		scanf("%d%d%d", &T1[i].usingKey, &T1[i].begin, &tmp);
		T1[i].end = T1[i].begin + tmp;
		if (T1[i].end > maxTime) {
			maxTime = T1[i].end;
		}	
		T2[i] = T1[i];
	}
	sort(T1, T1 + K, cmp1); // 将老师们按使用钥匙的时间排序
	sort(T2, T2 + K, cmp2); // 将老师们按归还钥匙的时间排序 
	// 进行每一个时刻 
 	for (int i = 1; i <= maxTime; i++) {
 		// 每个时刻对老师扫描一遍, 进行归还和借出 
		// 归还 
		for (int j = 0; j < K; j++) {
			if (T2[j].end == i) {
				for (int u = 1; u <= N; u++) {
					if (key[u] == -1) {
						key[u] = T2[j].usingKey;
						pos[T2[j].usingKey] = u;
						break;
					} 
				}
			}
			if (T2[j].end > i) {
				break;
			}
		}
		// 借出 
		for (int j = 0; j < K; j++) {
 			if (T1[j].begin == i) {
 				key[pos[T1[j].usingKey]] = -1;	
 				pos[T1[j].usingKey] = -1;
			}
			if (T1[j].begin > i) {
				break;
			}
		}
		// test
		/*
		printf("time = %d ", i);
		for (int j = 1; j <= N; j++) { 
			if (j - 1) {
				printf(" ");
			}
			printf("%d", key[j]);
		}	 
		printf("\n"); 
		*/
	} 
	for (int i = 1; i <= N; i++) {
		if (i - 1) {
			printf(" ");
		}
		printf("%d", key[i]);
	} 
	return 0;
} 
