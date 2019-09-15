#include <cstdio>
#include <cstring>

const int maxn = 303;
int b[maxn];
int a[maxn];
int memo[maxn][maxn][maxn];
int n;

int dfs(int x, int y, int pos) {
    if (pos == 1) {
        for (int i = 2 * b[0] - a[0]; i <= 2 * b[0] - a[0] + 1; i++) {
            if (i > 0) {
                a[pos] = i;
                if (dfs(y, i, pos + 1)) return 1;
            }
        }
        return 0;
    } else if (pos == n - 1) {
        int cand1 = 2 * b[n - 1] - a[n - 2];
        int cand2 = 2 * b[n - 1] - a[n - 2] + 1;
        if (cand1 > 0 && (cand1 + a[pos - 1] + a[pos - 2]) /3 == b[pos - 1]) {
            memo[a[pos - 1]][cand1][pos] = 1;
            a[pos] = cand1;
            return 1;
        }
        else if (cand2 > 0 && (cand2 + a[pos - 1] + a[pos - 2]) / 3 == b[pos - 1]) {
            memo[a[pos - 1]][cand2][pos] = 1;
            a[pos] = cand2;
            return 1;
        }
    } else {
        if (memo[x][y][pos] != -1) return memo[x][y][pos];
        int base = 3 * b[pos - 1] - a[pos - 2] - a[pos - 1];
        for (int i = base; i <= base + 2; i++) {
            if (i > 0) {
                a[pos] = i;
                if (dfs(a[pos - 2], i, pos + 1)) return 1;
            }
        }
    }
    memo[x][y][pos] = 0;
    return 0;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    memset(memo, -1, sizeof(memo));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= 2 * b[0]; i++) {
        a[0] = i;
        if (dfs(-1, i, 1)) break;
    }
    for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
    return 0;
}