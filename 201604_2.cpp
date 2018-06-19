#include <cstdio>

void printBoard(int board[][11]) {
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= 10; j++) {
			if (j != 1) {
				printf(" ");
			}
			printf("%d", board[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int board[16][11];
	// ����ԭʼ���� 
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	// ��������ͼ������¼ÿһ���������1����ͼ������һ��λ�� 
	int block[5][5];
	int pos[5][5] = {0}; // ��¼ͼ����ԭʼ���λ�� 
	int begin; // ͼ����ʼ������ 
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			scanf("%d", &block[i][j]);
			if (block[i][j] == 1) {
				pos[i][j] = 1;
			} 
		}
	}
	scanf("%d", &begin);
	
	// ���������block
	/*
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (j != 1) {
				printf(" ");
			}
			printf("%d", block[i][j]);
		}
		printf("\n");
	} 
	*/
	
	// ��ʼģ��ͼ������Ĺ��� 
	
	// ���Ƚ�ͼ���������̶���
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			board[i][j + begin -1] = block[i][j];
		}
	}
	
	// ��ʼ����
	bool flag = false; // flagΪtrueʱ, �����ϰ�, ֹͣ����
	for (int k = 1; k <= 11; k++) { // ����15�е�������˵���ֻ������11��(����4*4��ͼ��)
		// ��������
		for (int i = 4; i >= 1; i--) {
			for (int j = 1; j <= 4; j++) {
				if (board[k + i - 1][j + begin - 1] && board[k + i][j + begin - 1]) { // �������ϰ� 
					flag = true;
					break;
				} 
				if (pos[i][j]) {
					board[k + i][j + begin - 1] = board[k + i - 1][j + begin - 1];
					board[k + i - 1][j + begin - 1] = 0;
				}
			}
			if (flag) {
				break;
			}
		} 
		// test
		// printBoard(board);
		// printf("yaha\n");
		if (flag) {
			break;
		}
	}
	// ����ͼ������֮��, �ٴ���ͼ���ڲ�������
	if (flag == false) { // ��flag=true, ��˵�������֮ǰ�������ϰ�, ���ؼ��������� 
		for (int k = 1; k <= 3; k++) { // ����ͼ���ڲ�, ���ֻ������3�� 
			for (int i = 4; i >= 1; i--) {
				for (int j = 1; j <=  4; j++) {
						if (pos[i][j] && (k + i - 1) == 4) { // ˵�������� 
							flag = true;
							break;
						}
						if (pos[i][j] && (k + i) <= 4 && board[k + i][j + begin - 1] == 1) { // ˵����ײ�� 
							flag = true;
							break;
						}
						if (k + i <= 4 && pos[i][j]) {
							board[11 + k + i][j + begin - 1] = board[11 + k + i - 1][j + begin -1];
							board[11 + k + i - 1][j + begin - 1] = 0;
						}
				}
				if (flag) {
					break;
				}
			}
			// test
			// printBoard(board);
			// printf("yoho\n");
			if (flag) {
				break;
			}
		}
	} 
	// ������ս�� 
	printBoard(board);
	return 0;
} 
