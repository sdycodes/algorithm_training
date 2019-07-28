#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define reopen do{if(DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{if(DEBUG){printf("##DEBUG##");printf(__VA_ARGS__);printf("\n");}}while(0)
#define showarray(lo, hi, a) do{if(DEBUG){for(int _x=lo;_x<hi;_x++) printf("%d", a[_x]);printf("\n");}}while(0)

int checkrow(int row, int board[][9]) {
    int check[10];
    memset(check, 0, sizeof(check));
    for (int i = 0; i < 9; i++) {
        check[board[row][i]] = 1;
    }
    for (int i = 1; i <= 9; i++) {
        if (check[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int checkcol(int col, int board[][9]) {
    int check[10];
    memset(check, 0, sizeof(check));
    for (int i = 0; i < 9; i++) {
        check[board[i][col]] = 1;
    }
    for (int i = 1; i <= 9; i++) {
        if (check[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int checksquare(int x, int y, int board[][9]) {
    int check[10];
    memset(check, 0, sizeof(check));
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            check[board[i][j]] = 1;
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (check[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    reopen;
    int n;
    scanf("%d", &n);
    while(n--) {
        int board[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        int flag = 1;
        for (int i = 0; i < 9; i++) {
            if (checkrow(i, board) == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < 9; i++)  {
                if (checkcol(i, board) == 0) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            for (int i = 0; i < 9; i += 3) {
                for (int j = 0; j < 9; j += 3) {
                    if (checksquare(i, j, board) == 0) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag) {
            printf("Right\n");
        } else {
            printf("Wrong\n");
        }
    }
    return 0;
}