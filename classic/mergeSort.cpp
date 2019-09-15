#include <cstdio>
 
const int maxn = 10005;
int a[maxn], t[maxn];
int cnt;
void merge_sort(int a[], int l, int r, int t[]) {
    if (r - l <= 1) return;
    int m = l + (r - l) / 2;
    merge_sort(a, l, m, t);
    merge_sort(a, m, r, t);
    int p = l, q = m, pos = l;
    while(p < m || q < r) {
        if (q >= r || (p < m && a[p] <= a[q])) {
            t[pos++] = a[p++];
        } else {
            t[pos++] = a[q++];
            cnt += m - p;
        }
    }
    for (int i = l; i < r; i++) {
        a[i] = t[i];
    }
    return;
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
    cnt = 0;
    merge_sort(a, 0, n, t);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    printf("reverse cnt: %d\n", cnt);
    return 0;
}