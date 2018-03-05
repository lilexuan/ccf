#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int hashTable[10001];
	fill(hashTable, hashTable + 10001, 0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		hashTable[num]++;
		if (i) {
			printf(" ");
		}
		printf("%d", hashTable[num]);
	}
	return 0;
}
