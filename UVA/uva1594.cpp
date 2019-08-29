#include <iostream>
#include <cstdio>
#include <cstring>

#define maxn 15 + 5

int a[maxn];
int n;

void add() {
    int b[maxn];
    for (int i = 0; i < n - 1; i++) {
        b[i] = abs(a[i] - a[i + 1]);
    }
    b[n - 1] = abs(a[n - 1] - a[0]);
    memcpy(a, b, n * sizeof(int));
    return;
}

bool all_zero() {
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;
}

bool judge() {
    for (int i = 0; i < 1005; i++) {
        add();
        if (all_zero()) {
            return true;
        }
    }
    return false;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if (judge()) {
            printf("ZERO\n");
        } else {
            printf("LOOP\n");
        }
    }
    return 0;
}