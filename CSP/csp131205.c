#include <stdio.h>
char a[60][60];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int R, C;
int vis[60][60];
int res;
int bfs(int x, int y) {
	if (x < 0 || y < 0 || x >= R || y >= C) {
		return 0;
	}
	if (a[x][y] == '#' || vis[x][y] == 1) {
		return 0;
	}
	if (a[x][y] == 'T') {
		return 1;
	}
	vis[x][y] = 1;
	int high, low;
	if (a[x][y] == 'S' || a[x][y] == '+') {
		low = 0;
		high = 4;
	} else if (a[x][y] == '|') {
		low = 2;
		high = 4;
	} else if (a[x][y] == '-') {
		low = 0;
		high = 2;
	} else if (a[x][y] == '.') {
		low = 3;
		high = 3;
	}
	int reach = 0;
	for (int i = low; i < high; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (i == 1 && y - 1 >= 0 && a[x][y-1] == '.') {
			continue;
		}
		reach = reach || bfs(nx, ny);	
	}
	if (reach == 0) {
		res += 1;
	}
	return reach;
}

int main(int argc, char *argv[]) {
	scanf("%d%d", &R, &C);
	getchar();
	int sx, sy;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &a[i][j]);
			if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			vis[i][j] = 0;
		}
		getchar();
	}
	if (bfs(sx, sy) == 0) {
		printf("I'm stuck!\n");
	} else {
		printf("%d\n", res - 1);
	}
}