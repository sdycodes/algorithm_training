#include <cstdio>
const int maxn = 10005;
int a[maxn];

//左闭右开
int bsearch(int a[], int x, int y, int v) {
    int m;
    while(x < y) {
        m = x + (y - x) / 2;
        if (a[m] == v) break;
        else if (a[m] > v) y = m;
        else x = m + 1;
    }
    return -1;
}

// 如果v存在 返回第一个v 否则在返回的位置前面插v保序
int lower_bound(int a[], int x, int y, int v) {
    int m;
    while(x < y) {
        m = x + (y - x) / 2;
        if (a[m] >= v) y = m;
        else x = m + 1;
    }
    return x;
}

// 如果v存在 返回最后一个v 否则在返回的位置前面插v保序
int upper_bound(int a[], int x, int y, int v) {
    int m;
    while(x < y) {
        m = x + (y - x) / 2;
        if (a[m] <= v) x = m + 1;
        else y = m;
    }
    return x;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int v;
    while(scanf("%d", &v)!=EOF) {
        printf("[%d, %d)\n", lower_bound(a, 0, n, v), upper_bound(a, 0, n, v));
    }
    return 0;
}