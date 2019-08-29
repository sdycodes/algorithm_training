#include <iostream>
#include <cstdio>
#define maxn 100005
int right[maxn], left[maxn];

void link(int l, int r) {
    right[l] = r;
    left[r] = l;
}

void swap(int a, int b) {
    if (right[b] == a) {
        int t = a;
        a = b;
        b = t;
    }
    int la = left[a], ra = right[a], lb = left[b], rb = right[b];
    if (ra == b) {
        link(la, b);
        link(b, a);
        link(a, rb);
    } else {
        link(la, b);
        link(b, ra);
        link(lb, a);
        link(a, rb);
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif  
    int n, m, kase = 0;
    while(scanf("%d%d", &n, &m) != EOF) {
        kase++;
        right[0] = 1;
        left[0] = n;
        for (int i = 1; i <= n; i++) {
            right[i] = i + 1;
            left[i] = i - 1;
        }
        right[n] = 0;
        bool isRev = false;
        int op;
        for (int i = 0; i < m; i++) {
            scanf("%d", &op);
            if (op == 4) {
                isRev = !isRev;
            } else if (op == 3) {
                int x, y;
                scanf("%d%d", &x, &y);
                swap(x, y);
            } else {
                if (isRev) {
                    op = op % 2 + 1;
                }
                int x, y;
                scanf("%d%d", &x, &y);
                int lx = left[x], rx = right[x];
                int ly = left[y], ry = right[y];
                if (op == 2) {
                    if (ry == x) {
                        continue;
                    }
                    link(lx, rx);
                    link(x, ry);
                    link(y, x);
                } else {
                    if (ly == x) {
                        continue;
                    }
                    link(lx, rx);
                    link(ly, x);
                    link(x, y);
                }
            }
        }
        long long res = 0;
        int no = 0;
        for (int pos = 1; pos <= n; pos++) {
            no = right[no];
            //printf("%d ", no);
            if (pos % 2) {
                res += no;
            }
        }
        //printf("\n");
        printf("Case %d: %lld\n", kase, isRev?(long long)n * (n + 1) / 2 - res:res);
    }
    return 0;
}