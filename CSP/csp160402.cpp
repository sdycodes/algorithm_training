#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	//freopen("./data.in", "r", stdin);
	int board[15][10];
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	int pattern[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &pattern[i][j]);
		}
	}
	int loc;
	scanf("%d", &loc);
	//计算每一列最大下沉位置
	int botloc[4] = {4, 4, 4, 4};
	int toploc[4] = {15, 15, 15, 15};
	int maxloc[4];
	int realLayer = 100;
	for (int c = 0; c < 4; c++) {
		//找到pattern的最低位置
		for (int r = 3; r >= 0; r--) {
			if (pattern[r][c] != 0) {
				botloc[c] = r;
				break;
			}
		}
		//找到board的最高位置
		for (int r = 4; r < 15; r++) {
			if (board[r][loc + c -1] != 0) {
				toploc[c] = r;
				break;
			}
		}
		//计算各个列的最大下沉
		if (botloc[c] == 4) {
			maxloc[c] = 100;
		} else if (toploc[c] == 15) {
			maxloc[c] = 14 - botloc[c];
		} else {
			maxloc[c] = toploc[c] - 4 + (3 - botloc[c]);
		}
		if (realLayer > maxloc[c]) {
			realLayer = maxloc[c];
		}
	}
	if (realLayer != 100) {
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				if (pattern[r][c] == 1) { 
					board[realLayer + r][c + loc - 1] = pattern[r][c];
				}
			}
		}
	}
	for (int r = 0; r < 15; r++) {
		for (int c = 0; c < 10; c++) {
			printf("%d ", board[r][c]);
		}
		printf("\n");
	}
	return 0;
}