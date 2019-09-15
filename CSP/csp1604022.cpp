#include <cstdio>
#include <algorithm>
using namespace std;
int board[16][12];
int block[5][5];

int drop_down(int n) {
    int line = 4;
    int blank_bot = 0;
    for (int r = 4; r >= 1; r--) {
        if (!block[r][1] && !block[r][2] && !block[r][3] && !block[r][4]) {
            blank_bot++;
        } else {
            break;
        }
    }
    while(line <= 15 + blank_bot) {
        for (int r = 4 - blank_bot; r >= 1; r--) {
            for (int c = 1; c <= 4; c++) {
                if (block[r][c] && board[line - 4 + r][c + n - 1]) {
                    return line - 1;
                }
            }
        }
        line++;
    }
    return 15 + blank_bot;
}

void put_down(int r, int c) {
    for (int i = r; i < min(16, r + 4); i++) {
        for (int j = c; j < c + 4; j++) {
            board[i][j] = board[i][j] || block[i - r + 1][j - c + 1];
        }
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 10; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            scanf("%d", &block[i][j]);
        }
    }
    int n;
    scanf("%d", &n);
    int line = drop_down(n);
    put_down(line - 3, n);
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
