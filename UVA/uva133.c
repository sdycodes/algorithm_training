#include <stdio.h>

int a[25];
int N, k, m;
//go 函数应该具有跳过空格的能力
int go(int cur, int dir, int len) {
    int res = cur;
    while(len--) {
        do{
            res = (res + dir + N) % N;
        } while(a[res] == 0);
    }
    return res;
}

int main() {
    #ifdef D
        printf("Debug mode\n");
        freopen("data.in", "r", stdin);
    #endif
    while(scanf("%d%d%d", &N, &k, &m) != EOF) {
        if (N == 0 && k == 0 && m == 0) {break;}
        int left = N;
        for (int i = 0; i < N; i++){
            a[i] = i + 1;
        }
        int p1 = N - 1, p2 = 0;
        while(left > 0) {
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            printf("%3d", a[p1]);
            left--;
            if (p1 != p2) {
                printf("%3d", a[p2]);
                left--;
            }
            a[p1] = 0;
            a[p2] = 0;
            if (left) {
                printf(",");
            } else {
                printf("\n");
            }
        }
    }
}