#include <cstdio>
#include <cstring>

int seat[22][6];

void search(int p) {
    int ri = -1, rc;
    for (int i = 1; i <= 20; i++) {
        int blank = 0, maxlen = 0, trc = 5;
        for (int j = 1; j <= 5; j++) {
            if (seat[i][j] == 0) {
                blank++;
                if (maxlen < p && blank > maxlen) {
                    maxlen = blank;
                    trc = j;
                }
            }
            else blank = 0;
        }
        if (maxlen >= p) {
            ri = i;
            rc = trc;
            break;
        }
    }
    if (ri == -1) {
        int cnt = 0;
        for (int i = 1; i <=20; i++) {
            for (int j = 1; j <= 5; j++) {
                if (seat[i][j] == 0) {
                    seat[i][j] = 1;
                    printf("%d ", (i - 1) * 5 + j);
                    cnt++;
                    if (cnt == p) {
                        printf("\n");
                        return;
                    }
                }
            }
        }
    } else {
        for (int j = rc - p + 1; j <= rc; j++) {
            seat[ri][j] = 1;
            printf("%d ", (ri - 1)* 5 + j);
        }
    }
    printf("\n");
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    memset(seat, 0, sizeof(seat));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        search(p);
    }
    return 0;
}