#include <cstdio>

int a[501][501];
int n;

void toRight(int &i, int &j) {
	j++;
	printf(" %d", a[i][j]);
}

void toDown(int &i, int &j) {
	i++;
	printf(" %d", a[i][j]);
}

void toLeftDown(int &i, int &j) {
	i++;
	j--;
	printf(" %d", a[i][j]);
}

void toRightUp(int &i, int &j) {
	i--;
	j++;
	printf(" %d", a[i][j]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d", a[0][0]);
	if (n == 1) {
		return 0; // ������� 
	}
	int i = 0, j = 0;
	while (true) {
		// ����һ, ����(��������һ�о�����) 
		if (j < n - 1) {
			toRight(i, j);
		} else {
			toDown(i, j);
		}
		// �����, б���� 
		while (j >= 1 && i <= n - 2) {
			toLeftDown(i, j);
		}
		// ������, ����(��������һ�оͺ���)
		if (i < n - 1) {
			toDown(i, j);
		} else {
			toRight(i, j);
		}
		// ������, б���� 
		if (i == n - 1 && j == n - 1) { // �ߵ�ĩβ��, �˳� 
			break;
		} else {
			while (j <= n - 2 && i >= 1) {
				toRightUp(i, j);
			}
		}
	}
	return 0;
}
