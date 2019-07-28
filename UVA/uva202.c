#include <stdio.h>
#include <string.h>

const int maxn = 3000 + 100;
int vis[maxn];
int rec[maxn];

int main() {
#ifdef DEBUG
    freopen("data.in", "r", stdin);
#endif
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        memset(vis, -1, sizeof(vis));
        int p = 0;
        int ra = a;
        rec[p++] = a / b;
        a %= b;
        while(a && vis[a] == -1) {
            rec[p++] = (a * 10) / b;
            vis[a] = p - 1;
            a = (a * 10) % b;
        }
        printf("%d/%d = %d.", ra, b, rec[0]);
        int loop_begin_pos = a == 0 ? p : vis[a];
        //printf("   loop pos: %d\n", loop_begin_pos);
        for (int i = 1; i < loop_begin_pos; i++) {
            printf("%d", rec[i]);
        }
        printf("(");
        if (a == 0) {
            printf("0");
        } else {
            int upper = p <= (loop_begin_pos + 50)? p : (loop_begin_pos + 50);
            for (int i = loop_begin_pos; i < upper; i++) {
                printf("%d", rec[i]);
            }
            if (upper < p) {
                printf("...");
            }
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", a? p - loop_begin_pos: 1);
    }

    return 0;
}