#include <cstdio>
#include <cstring>
#include <cctype>

// (A(B()C(E()F())D(G())))
// (A(B()C(E()F())D(G())))
// (e(f()g()))
// (e(f()g()))
char T[205][205];
int lines;

void draw_tree(int r, int c) {
    printf("%c(", T[r][c]);
    if (r + 1 >= lines || T[r + 1][c] != '|') {
        printf(")");
        return;
    }
    int left = c;
    while(left >= 0 && T[r + 2][left] == '-') {
        left--;
    }
    left++;
    int right = c;
    while(right < strlen(T[r + 2]) && T[r + 2][right] == '-') {
        right++;
    }
    for (int i = left; i < right; i++) {
        if (!isspace(T[r + 3][i]) && T[r + 3][i] != '\0') {
            draw_tree(r + 3, i);
        }
    }
    printf(")");
    return;
}

void read_case() {
    lines = 0;
    memset(T, 0, sizeof(T));
    while(fgets(T[lines], 203, stdin) && T[lines][0] != '#') {
        lines++;
    }
    return;
}

// 1 空树处理
// 2 isspace 
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int K;
    scanf("%d", &K);
    getchar();
    while(K--) {
        read_case();
        if (lines == 0) {
            printf("()\n");
            continue;
        }
        printf("(");
        for (int i = 0; i < strlen(T[0]); i++) {
            if (T[0][i] != ' ') {
                draw_tree(0, i);
                break;
            }
        }
        printf(")\n");
    }
    return 0;
}
