#include <stdio.h>
#include <string.h>

char board[15][15];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void printB() {
    #ifndef D
        return;
    #endif
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 9; j++) {
            if (board[i][j] == 0)
                printf(". ");
            else 
                printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("=================\n");
}
void placeG(int r, int c) {
    int i = r - 1;
    while(i >= 1 && (board[i][c] == 0 || board[i][c] == 'x')) {
        if (board[i][c] == 'x') {
            board[i][c] = 0;
        }
        i--;
    }
}

void placeR(int r, int c) {
    int i = r - 1;
    while(i >= 1 && (board[i][c] == 0 || board[i][c] == 'x')) {
        if (board[i][c] == 'x') {
            board[i][c] = 0;
        }
        i--;
    }
    i = r + 1;
    while(i <= 10 && (board[i][c] == 0 || board[i][c] == 'x')) {
        if (board[i][c] == 'x') {
            board[i][c] = 0;
        }
        i++;
    }
    int j = c + 1;
    while(j <= 10 && (board[r][j] == 0 || board[r][j] == 'x')) {
        if (board[r][j] == 'x') {
            board[r][j] = 0;
        }
        j++;
    }
    j = c - 1;
    while(j >= 1 && (board[r][j] == 0 || board[r][j] == 'x')) {
        if (board[r][j] == 'x') {
            board[r][j] = 0;
        }
        j--;
    }
}

void placeH(int r, int c) {
    int nmover[4][2] = {{1, 1}, {-1, -1}, {-1, 1}, {-1, 1}};
    int nmovec[4][2] = {{-1, 1}, {-1, 1}, {1, 1}, {-1, -1}};
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 1 && nr <= 10 && nc >= 1 && nc <= 9 && (board[nr][nc] == 0 || board[nr][nc] == 'x')) {
            for (int j = 0; j < 2; j++) {
                int tr = nr + nmover[i][j];
                int tc = nc + nmovec[i][j];
                if (tr >= 1 && tr <= 10 && tc >= 1 && tc <= 9) {
                    if (board[tr][tc] == 'x') {
                        board[tr][tc] = 0;
                    }
                }
            }
        }
    }
}

void placeC(int r, int c) {
    int i = r + 1;
    int cnt = 0;
    while(i <= 10) {
        if (board[i][c] != 0 && board[i][c] != 'x') {
            cnt++;
            if (cnt == 2) {
                break;
            }
        }
        if (board[i][c] == 'x' && cnt == 1) {
            board[i][c] = 0;
        }
        i++;
    }
    cnt = 0;
    i = r - 1;
    while(i >= 1) {
        if (board[i][c] != 0 && board[i][c] != 'x') {
            cnt++;
            if (cnt == 2) {
                break;
            }
        }
        if (board[i][c] == 'x' && cnt == 1) {
            board[i][c] = 0;
        }
        i--;
    }
    cnt = 0;
    int j = c + 1;
    while(j <= 9) {
        if (board[r][j] != 0 && board[r][j] != 'x') {
            cnt++;
            if (cnt == 2) {
                break;
            }
        }
        if (board[r][j] == 'x' && cnt == 1) {
            board[r][j] = 0;
        }
        j++;
    }
    j = c - 1;
    while(j >= 1) {
        if (board[r][j] != 0 && board[r][j] != 'x') {
            cnt++;
            if (cnt == 2) {
                break;
            }
        }
        if (board[r][j] == 'x' && cnt == 1) {
            board[r][j] = 0;
        }
        j--;
    }
}

int judge(int bx, int by) {
    for (int i = 0; i < 4; i++) {
        int nr = bx + dr[i];
        int nc = by + dc[i];
        if (nr >= 1 && nr <= 3 && nc >= 4 && nc <= 6) {
            if (board[nr][nc] == 0)
                board[nr][nc] = 'x';
        }
    }
    #ifdef D
            printB();
    #endif 
    for (int r = 1; r <= 10; r++) {
        for (int c = 1; c <= 9; c++) {
            switch(board[r][c]) {
                case 'G': placeG(r, c); printB(); break;
                case 'R': placeR(r, c); printB(); break;
                case 'H': placeH(r, c); printB(); break;
                case 'C': placeC(r, c); printB(); break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int nr = bx + dr[i];
        int nc = by + dc[i];
        if (nr >= 1 && nr <= 3 && nc >= 4 && nc <= 6) {
            if (board[nr][nc] == 'x') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int N, bx, by;
    while(scanf("%d%d%d", &N, &bx, &by)) {
        getchar();
        if (N == 0 && bx == 0 && by == 0) break;
        //printf("%d %d %d\n", N, bx, by);
        memset(board,0, sizeof(board));
        for (int i = 0; i < N; i++) {
            char p;
            int x, y;
            scanf("%c%d%d", &p, &x, &y);
            getchar();
            board[x][y] = p;
        }
        if (judge(bx, by)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}