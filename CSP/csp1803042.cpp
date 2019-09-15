#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int board[3][3];

int finish() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]) return board[i][0];
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j]) return board[0][j];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]) return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]) return board[0][2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) return 0;
        }
    }
    return -1;
}

int count() {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) cnt++;
        }
    }
    return cnt + 1;
}

int dfs(int player) {
    int pl = finish();
    if (pl == -1) return 0;
    else if (pl != 0) return pl == 1?count():-count();
    int res = 100;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = player;
                if (player == 1) {
                    if (res == 100) res = dfs(2);
                    else res = max(res, dfs(2));
                } else {
                    if (res == 100) res = dfs(1);
                    else res = min(res, dfs(1));
                }
                board[i][j] = 0;
            }
        }
    }
    return res;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(board, 0, sizeof(0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        printf("%d\n", dfs(1));
    }
    return 0;
}