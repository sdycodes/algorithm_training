#include <stdio.h>
#include <string.h>

char board[105][105];
int num[105][105];
int r, c;
void outputAcross() {
    printf("Across\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '*') continue;
            if (j == 0 || board[i][j - 1] == '*') {
                int k = j;
                printf("%3d.", num[i][k]);
                while(k < c && board[i][k] != '*') {
                    putchar(board[i][k]);
                    k++;
                }
                putchar('\n');
            }
        }
    }
}

void outputDown() {
    printf("Down\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '*') continue;
            if (i == 0 || board[i - 1][j] == '*') {
                int k = i;
                printf("%3d.", num[k][j]);
                while(k < r && board[k][j] != '*') {
                    putchar(board[k][j]);
                    k++;
                }
                putchar('\n');
            }
        }
    }
}

int main() {
    #ifdef DEBUG
        freopen("data.in", "r", stdin);
    #endif
    int T = 0;
    while(scanf("%d%d", &r, &c) == 2) {
        T++;
        getchar();
        memset(num, 0, sizeof(num));
        int cnt = 1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i][j] = getchar();
                if (board[i][j] == '*') continue;
                if (i == 0 || j == 0 || board[i-1][j] == '*' || board[i][j - 1] == '*') {
                    num[i][j] = cnt++;
                }
            }
            getchar();
        }
        if (T != 1) {
            printf("\n");
        }
        printf("puzzle #%d:\n", T);
        outputAcross();
        outputDown();
    }
    return 0;
}