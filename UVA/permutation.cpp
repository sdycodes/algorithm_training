#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 20;
int a[maxn];

//不是字典序 可重集
void perm(int a[], int n, int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = cur; i < n; i++) {
        int t = a[cur];
        a[cur] = a[i];
        a[i] = t;
        perm(a, n, cur + 1);
        t = a[cur];
        a[cur] = a[i];
        a[i] = t;
    }
}

//字典序 可重集
int b[maxn];
void perm_dic(int a[], int b[], int n, int cur) {
    //a 是cand
    //b 是放置
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", b[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        if (!i || a[i] != a[i - 1]) {
            int c1 = 0, c2 = 0;
            for (int j = 0; j < cur; j++) {
                if (a[i] == b[j]) c1++;
            }
            for (int j = 0; j < n; j++) {
                if (a[j] == a[i]) c2++;
            }
            if (c1 < c2) {
                b[cur] = a[i];
                perm_dic(a, b, n, cur + 1);
            }
        }
    }
    return;
}

//字典序 不可重集
void perm_dic_no_rep(int a[], int b[], int n, int cur) {
    //a cand
    //b 放置
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", b[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        int ok = 1;
        //可使用vis数组提速
        for (int j = 0; j < cur; j++) {
            if (a[i] == b[j]) ok = 0;
        }
        if (ok) {
            b[cur] = a[i];
            perm_dic_no_rep(a, b, n, cur + 1);
        }
    }
    return;
}

//STL 字典序 可重集
void perm_stl(int a[], int n) {
    do{
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }while(next_permutation(a, a + n));
}

//aplication n-皇后问题
int C[maxn]; // C[i]表示第i行皇后的列号
int vis[3][2 * maxn]; // 每个皇后占据的列和对角线
long long tot;

void n_queen(int cur, int n) {
    if (cur == n) {
        tot++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
            C[cur] = i;
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
            n_queen(cur + 1, n);
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
        }
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &a[i]);
    // }
    // sort(a, a + n);
    // perm_dic_no_rep(a, b, n, 0);
    // perm_stl(a, n);
    tot = 0;
    memset(vis, 0, sizeof(vis));
    n_queen(0, n);
    printf("%lld\n", tot);
    return 0;
}