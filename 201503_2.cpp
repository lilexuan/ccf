#include <cstdio>
#include <algorithm>
using namespace std;

struct Number {
	int val, times;
} nums[1001];

int hashTable[1001]; 

bool cmp(Number a, Number b) {
	if (a.times != b.times) {
		return a.times > b.times;
	} else {
		return a.val < b.val;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	fill(hashTable, hashTable + 1001, 0);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		hashTable[tmp]++;
	}
	int index = 0;
	for (int i = 0; i < 1001; i++) {
		if (hashTable[i] != 0) {
			Number num;
			num.val = i;
			num.times = hashTable[i];
			nums[index++] = num;
		}
	}
	sort(nums, nums + index, cmp);
	for (int i = 0; i < index; i++) {
		printf("%d %d\n", nums[i].val, nums[i].times);
	}
	return 0;
} 
