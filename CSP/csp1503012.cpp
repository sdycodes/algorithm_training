#include <cstdio>
const int maxn = 1005;
const int maxm = 1005;

int matrix[maxn][maxm];

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int j = m - 1; j>= 0; j--) {
        for (int i = 0; i < n; i++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}