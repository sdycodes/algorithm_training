#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 20;
int U[maxn];
int a[maxn];

// 增量构造法 字典序
void subset_cons(int n, int U[], int a[], int cur) {
    // U 所有元素的全集
    // a 当前子集的指标集
    for (int i = 0; i < cur; i++) printf("%d ", U[a[i]]);
    printf("\n");
    int s = cur?a[cur-1] + 1: 0;
    for (int i = s; i < n; i++) {
        a[cur] = i;
        subset_cons(n, U, a, cur + 1);
    }
    return;
}

// 位向量法  字典序不能保证
void subset_bv(int n, int U[], int b[], int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            if (b[i]) printf("%d ", U[i]);
        }
        printf("\n");
        return;
    }
    b[cur] = 1;
    subset_bv(n, U, b, cur + 1);
    b[cur] = 0;
    subset_bv(n, U, b, cur + 1);
    return;
}

// 位运算 简单非字典序
void subset_bit(int n, int U[]) {
    for (int s = 0; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) {
            if (s & (1 << i)) printf("%d ", U[i]);
        }
        printf("\n");
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &U[i]);
    }
    sort(U, U + n);
    // subset_cons(n, U, a, 0);
    // memset(a, 0, sizeof(a));
    // subset_bv(n, U, a, 0);
    subset_bit(n, U);
    return 0;
}