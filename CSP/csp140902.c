#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int main() {
    //freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int board[101][101];
    memset(board, 0, sizeof(board));
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2) {
            swap(&x1, &x2);
        }
        if (y1 > y2) {
            swap(&y1, &y2);
        }
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                board[x][y] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (board[i][j] == 1) {
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}