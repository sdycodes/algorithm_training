#include <stdio.h>
#include <string.h>

char g[500][500];
int a[55][55];
int b[55][55];
int m, n;
int maxr, maxu;

int max(int a, int b) {
    return a > b? a: b;
}

void place(int r, int c, int h) {
    int rg = maxu - (m - 1 - r) * 2 - 3 * (h - 1);
    int cg = c * 4 + 2 * (m - 1 - r);
    int p1x = rg, p1y = cg;
    int p2x = rg, p2y = p1y + 4;
    int p3x = p1x - 3, p3y = p1y;
    int p4x = p3x, p4y = p2y;
    int p5x = p3x - 2, p5y = p3y + 2;
    int p6x = p4x - 2, p6y = p4y + 2;
    int p7x = p2x - 2, p7y = p2y + 2;
    g[p1x][p1y] = '+';
    g[p2x][p2y] = '+';
    g[p3x][p3y] = '+';
    g[p4x][p4y] = '+';
    g[p5x][p5y] = '+';
    g[p6x][p6y] = '+';
    g[p7x][p7y] = '+';
    for (int i = p1y + 1; i < p2y; i++) {
        g[p1x][i] = '-';
    }
    for (int i = p3y + 1; i < p4y; i++) {
        g[p3x][i] = '-';
    }
    for (int i = p5y + 1; i < p6y; i++) {
        g[p5x][i] = '-';
    }
    for (int i = p1x - 1; i > p3x; i--) {
        g[i][p1y] = '|';
    }
    for (int i = p2x - 1; i > p4x; i--) {
        g[i][p2y] = '|';
    }
    for (int i = p7x - 1; i > p6x; i--) {
        g[i][p7y] = '|';
    }
    g[p2x - 1][p2y + 1] = '/';
    g[p3x - 1][p3y + 1] = '/';
    g[p4x - 1][p4y + 1] = '/';
    g[p1x - 1][p1y + 1] = ' ';
    g[p1x - 1][p1y + 2] = ' ';
    g[p1x - 2][p1y + 1] = ' ';
    g[p1x - 2][p1y + 2] = ' ';
    g[p1x - 1][p1y + 3] = ' ';
    g[p1x - 2][p1y + 3] = ' ';
    for (int i = p3y + 2; i <= p3y + 4; i++) {
        g[p3x - 1][i] = ' ';
    }
    g[p4x][p4y + 1] = ' ';
    g[p7x][p7y - 1] = ' ';
    return;
}


int main() {
    //freopen("drawing.in", "r", stdin);
    //freopen("drawing.out", "w+", stdout);
    memset(b, 0, sizeof(b));
    maxr = 0;
    maxu = 0;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &(a[i][j]));
            maxr = max(maxr, (j + 1) * 4 + 2 * (m - i));
            maxu = max(maxu, a[i][j] * 3 + 2 * (m - i));
        }
    }
    
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            g[i][j] = '.';
        }
    }
    int flag = 1;
    while(flag) {
        flag = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] < a[i][j]) {
                    b[i][j]++;
                    place(i, j, b[i][j]);
                    flag = 1;
                }
            }
        }
        
    }
    
    for (int i = 0; i <= maxu; i++) {
        for (int j = 0; j <= maxr; j++) {
            printf("%c", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}