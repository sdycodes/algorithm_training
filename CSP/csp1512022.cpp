#include <cstdio>
#include <cstring>

const int maxn = 35;
const int maxm = 35;
int board[maxn][maxm];
int is_delete[maxn][maxm];
int n, m;

void check() {
    // check row
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int k = 1; k <= m; k++) {
            if (board[i][k] == board[i][k - 1]) {
                cnt++;
            } else {
                if (cnt >= 3) {
                    for (int x = 1; x <= cnt; x++) {
                        is_delete[i][k - x] = 1;
                    }
                }
                cnt = 1;
            }
        }
    }
    // check colum
    for (int j = 0; j < m; j++) {
        int cnt = 1;
        for (int k = 1; k <= n; k++) {
            if (board[k][j] == board[k - 1][j]) {
                cnt++;
            } else {
                if (cnt >= 3) {
                    for (int x = 1; x <= cnt; x++) {
                        is_delete[k - x][j]  = 1;
                    }
                }
                cnt = 1;
            }
        }
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    memset(board, 0, sizeof(board));
    memset(is_delete, 0, sizeof(is_delete));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    check();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (is_delete[i][j]) printf("0 ");
            else printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}