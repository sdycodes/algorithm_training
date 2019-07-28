#include <stdio.h>

#define DEBUG 0
#define reopen do{if(DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{if(DEBUG){printf("##DEBUG## ");printf(__VA_ARGS__);printf("\n");}}while(0)

int abs(int a) {
    return a < 0? -a:a;
}
void sort(int a[], int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int r = a[lo];
    int i = lo, j = hi;
    while(i < j) {
        while(i < j && a[j] >= r) {
            j--;
        }
        while(i < j && a[i] <= r) {
            i++;
        }
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    a[lo] = a[i];
    a[i] = r;
    sort(a, lo, i - 1);
    sort(a, i + 1, hi);
}

int main() {
    reopen;
    int n;
    scanf("%d", &n);
    int a[10005];
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &a[i]);
    }
    sort(a, 0, n - 1);
    int mid = a[n / 2];
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(a[i] - mid);
    }
    printf("%d\n", res);
    return 0;
}
