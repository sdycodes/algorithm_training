#include <stdio.h>
struct window{
    int x1, y1, x2, y2, no;
};
typedef struct window Window;


int main() {
    //freopen("data.in", "r", stdin);
    int N, M;
    scanf("%d%d", &N, &M);
    Window a[15];
    for (int i = N - 1; i >= 0; i--) {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        a[i].no = N - i;
    }
    int p[15][2];
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &p[i][0], &p[i][1]);
    }
    for (int i = 0; i < M; i++) {
        int j = 0;
        int flag = -1;
        for (j = 0; j < N; j++) {
            if (p[i][0] <= a[j].x2 && p[i][0] >= a[j].x1 && p[i][1] >= a[j].y1 && p[i][1] <= a[j].y2) {
                flag = j;
                break;
            }
        }   
        if (flag == -1) {
            printf("IGNORED\n");
        } else {
            printf("%d\n", a[j].no);
            int tmpx1 = a[j].x1;
            int tmpx2 = a[j].x2;
            int tmpy1 = a[j].y1;
            int tmpy2 = a[j].y2;
            int tmpno = a[j].no;
            for (int k = j; k >= 1; k--) {
                a[k].x1 = a[k - 1].x1;
                a[k].x2 = a[k - 1].x2;
                a[k].y1 = a[k - 1].y1;
                a[k].y2 = a[k - 1].y2;
                a[k].no = a[k - 1].no;
            }
            a[0].x1 = tmpx1;
            a[0].x2 = tmpx2;
            a[0].y1 = tmpy1;
            a[0].y2 = tmpy2;
            a[0].no = tmpno;
        }
    }
    return 0;
}