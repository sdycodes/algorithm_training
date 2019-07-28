#include <stdio.h>

char board[10][10];

int move(int legal, int* x, int* y, char move) {
    if (!legal) {
        return legal;
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int tmp;
    if (move == 'A') {
        tmp = 0;
    } else if (move == 'B') {
        tmp = 1;
    } else if (move == 'L') {
        tmp = 2;
    } else {
        tmp = 3;
    }
    int newx = *x + dx[tmp];
    int newy = *y + dy[tmp];
    if (newx < 0 || newx >= 5 || newy < 0 || newy >= 5) {
        return 0;
    }
    board[*x][*y] = board[newx][newy];
    board[newx][newy] = ' ';
    *x = newx;
    *y = newy;
    return 1;
}

void output(int legal, int cnt) {
    if (cnt != 1) {
        printf("\n");
    }
    printf("Puzzle #%d:\n", cnt);
    if (legal) {
        for (int i = 0; i < 5; i++) {
            printf("%c %c %c %c %c\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
        }
        return;
    }
    printf("This puzzle has no final configuration.\n");
    return;
}


int main() {
    #ifdef DEBUG
        freopen("./data.in", "r", stdin);
    #endif
    int cnt = 0;
    while((board[0][0] = getchar()) != 'Z' ) {
        cnt++;
        for (int j = 1; j <= 4; j++) {
            board[0][j] = getchar();
        }
        getchar();
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j < 5; j++) {
                board[i][j] = getchar();
            }
            getchar();
        }
        int x, y;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == ' ') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        char act;
        int legal = 1;
        while ((act = getchar()) != '0') {
            if (act != 'A' && act != 'B' && act != 'L' && act != 'R') {
                continue;
            }
            legal = move(legal, &x, &y, act);
            //output(1, cnt);
        }
        getchar();
        output(legal, cnt);
    }
}