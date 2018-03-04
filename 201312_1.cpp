#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int hashTable[10001];
	fill(hashTable, hashTable + 10001, 0);
	int i;
	for (i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		hashTable[tmp]++;
	}
	int max = -1, ans = 1; // ��Ȼ��max��ansŪ����....�����Ƿ��˸��ͼ����� 
	for (i = 1; i < 10001; i++) {
		if (hashTable[i] > max) {
			max = hashTable[i];
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
} 
