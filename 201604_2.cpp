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
	// 输入原始棋盘 
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	// 输入掉落的图案并记录每一列最下面的1处于图案的哪一个位置 
	int block[5][5];
	int pos[5][5] = {0}; // 记录图案的原始相对位置 
	int begin; // 图案开始的列数 
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			scanf("%d", &block[i][j]);
			if (block[i][j] == 1) {
				pos[i][j] = 1;
			} 
		}
	}
	scanf("%d", &begin);
	
	// 测试输入的block
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
	
	// 开始模拟图案下落的过程 
	
	// 首先将图案放入棋盘顶部
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			board[i][j + begin -1] = block[i][j];
		}
	}
	
	// 开始下落
	bool flag = false; // flag为true时, 碰到障碍, 停止下落
	for (int k = 1; k <= 11; k++) { // 对于15行的棋盘来说最多只会下落11次(整个4*4的图案)
		// 单次下落
		for (int i = 4; i >= 1; i--) {
			for (int j = 1; j <= 4; j++) {
				if (board[k + i - 1][j + begin - 1] && board[k + i][j + begin - 1]) { // 碰到了障碍 
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
	// 整个图案到底之后, 再处理图案内部的下落
	if (flag == false) { // 若flag=true, 则说明在落地之前碰到了障碍, 不必继续处理了 
		for (int k = 1; k <= 3; k++) { // 对于图案内部, 最多只会下落3次 
			for (int i = 4; i >= 1; i--) {
				for (int j = 1; j <=  4; j++) {
						if (pos[i][j] && (k + i - 1) == 4) { // 说明到底了 
							flag = true;
							break;
						}
						if (pos[i][j] && (k + i) <= 4 && board[k + i][j + begin - 1] == 1) { // 说明碰撞了 
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
	// 输出最终结果 
	printBoard(board);
	return 0;
} 
