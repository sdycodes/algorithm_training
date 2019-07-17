#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
	//freopen("./data.in", "r", stdin);
	int board[31][31];
	bool can[31][31];
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
			can[i][j] = false;
		}
	}
	//check row
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 1; j < m; j++) {
			if (board[i][j] == board[i][j - 1]) {
				cnt++;
				if (cnt == 3) {
					can[i][j] = true;
					can[i][j - 1] = true;
					can[i][j - 2] = true;
				} else if (cnt > 3) {
					can[i][j] = true;
				}
			} else {
				cnt = 1;
			}
		}
	}
	// check colum
	for (int j = 0; j < m; j++) {
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (board[i][j] == board[i - 1][j]) {
				cnt++;
				if (cnt == 3) {
					can[i][j] = true;
					can[i - 1][j] = true;
					can[i - 2][j] = true;
				} else if (cnt > 3) {
					can[i][j] = true;
				}
			} else {
				cnt = 1;
			}
		}
	}
	// output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (can[i][j]) {
				printf("0 ");
			} else {
				printf("%d ", board[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}