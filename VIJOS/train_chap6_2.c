#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *p1, const void *p2) {
    return (*(int*)p1) - *((int*)p2);
}

int main() {
    int n;
    int a[105];
    int show[1005];
    memset(show, 0, sizeof(show));
    int b[105];
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (show[a[i]] == 0) {
            show[a[i]] = 1;
            b[cnt++] = a[i];
        }
    }
    qsort(b, cnt, sizeof(int), comp);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}