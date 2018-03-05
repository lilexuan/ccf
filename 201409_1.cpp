#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	bool hashTable[10001];
	fill(hashTable, hashTable + 10001, false);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		hashTable[num] = true;
	}
	int index = 0;
	int cnt = 0;
	while (index <= 10000) {
		if (hashTable[index] == false) {
			index++;
			continue;
		} else if (hashTable[index] == true) {
			index++;
			if (index > 10000) {
				break;
			}
			while (hashTable[index] == true) {
				cnt++;
				index++;
				if (index > 10000) {
					break;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
} 
