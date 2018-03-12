#include <cstdio>

const int MAXSIZE = 31;

int a[MAXSIZE][MAXSIZE];
int b[MAXSIZE][MAXSIZE];
int n, m;

int scanUp(int i, int j) {
	int killNum = 0;
	int nowColor = a[i][j];
	while (i >= 0) {
		if (a[i][j] == nowColor) {
			killNum++;
			nowColor = a[i][j];
		} else {
			break;
		}
		i--;
	}
	if (killNum >= 3) return killNum;
	else return 0;
}

int scanDown(int i, int j) {
	int killNum = 0;
	int nowColor = a[i][j];
	while (i <= n - 1) {
		if (a[i][j] == nowColor) {
			killNum++;
			nowColor = a[i][j];
		} else {
			break;
		}
		i++;
	}
	if (killNum >= 3) return killNum;
	else return 0;
}

int scanLeft(int i, int j) {
	int killNum = 0;
	int nowColor = a[i][j];
	while (j >= 0) {
		if (a[i][j] == nowColor) {
			killNum++;
			nowColor = a[i][j];
		} else {
			break;
		}
		j--;
	}
	if (killNum >= 3) return killNum;
	else return 0;
}

int scanRight(int i, int j) {
	int killNum = 0;
	int nowColor = a[i][j];
	while (j <= n - 1) {
		if (a[i][j] == nowColor) {
			killNum++;
			nowColor = a[i][j];
		} else {
			break;
		}
		j++;
	}
	if (killNum >= 3) return killNum;
	else return 0;
}

void kill(int killNum, char cmd[], int i, int j) {
	if (cmd[0] == 'u') {
		while (killNum--) {
			b[i--][j] = 0;
		}
	} else if (cmd[0] == 'd') {
		while (killNum--) {
			b[i++][j] = 0;
		}
	} else if (cmd[0] == 'l') {
		while (killNum--) {
			b[i][j--] = 0;
		}
	} else if (cmd[0] == 'r') {
		while (killNum--) {
			b[i][j++] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			b[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int killNum = scanUp(i, j);
			kill(killNum, "up", i, j);
			killNum = scanDown(i, j);
			kill(killNum, "down", i, j);
			killNum = scanLeft(i, j);
			kill(killNum, "left", i, j);
			killNum = scanRight(i, j);
			kill(killNum, "right", i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j != 0) {
				printf(" ");
			}
			printf("%d", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
