#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int posTable[1001];
	int negTable[1001];
	fill(posTable, posTable + 1001, 0);
	fill(negTable, negTable + 1001, 0);
	int i;
	for (i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if (num > 0) {
			posTable[num]++;
		} else if (num < 0) {
			negTable[-num]++; 
		}
	}
	int cnt = 0;
	for (i = 0; i < 1001; i++) {
		if (posTable[i] > 0 && negTable[i] > 0) {
			cnt += min(posTable[i], negTable[i]);
		}
	}
	printf("%d\n", cnt);
	return 0;
}
