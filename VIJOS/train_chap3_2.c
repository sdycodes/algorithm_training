#include <stdio.h>

#define DEBUG 1
#define reopen do{if (DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{if (DEBUG) {printf("DEBUG: ");printf(__VA_ARGS__);printf("\n");}}while(0)

void judge(int x, int y, int z) {
    if (z / x == 3 && z % x == 0 && y / x == 2 && y % x == 0) {
        printf("%d %d %d\n", x, y, z);
    }
}
void permutation(int cur, int n, int a[]) {
    if (cur == n) {
        int x = a[1] * 100 + a[2] * 10 + a[3];
        int y = a[4] * 100 + a[5] * 10 + a[6];
        int z = a[7] * 100 + a[8] * 10 + a[9];
        judge(x, y, z);
        //judge(x, z, y);
        //judge(y, x, z);
        //judge(y, z, x);
        //judge(z, x, y);
        //judge(z, y, x);
        return;
    }
    for (int j = cur; j <= n; j++) {
        int tmp = a[j];
        a[j] = a[cur];
        a[cur] = tmp;
        permutation(cur + 1, n, a);
        tmp = a[j];
        a[j] = a[cur];
        a[cur] = tmp;
    }
}
int main() {
    reopen;
    int a[10];
    for (int i = 1; i <= 9; i++) {
        a[i] = i;
    }
    permutation(1, 9, a);
    return 0;
}