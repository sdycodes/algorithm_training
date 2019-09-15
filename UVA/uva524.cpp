#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int isPrime(int n) {
    if (n <= 3) return n - 1 > 0;
    if ((n - 1) % 6 != 0 && (n + 1) % 6 != 0) return 0;
    for (int i = 5; i < sqrt(n) + 1; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int prime[50];
int circle[20];
int use[20];
void perm(int cur, int n) {
    if (cur == n) {
        if (prime[circle[n - 1] + 1]) {
            for (int i = 0; i < n - 1; i++) printf("%d ", circle[i]);
            printf("%d\n", circle[n - 1]);
        }
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!use[i] && prime[i + circle[cur-1]]) {
            circle[cur] = i;
            use[i] = 1;
            perm(cur + 1, n);
            use[i] = 0;
        }
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    for (int i = 0; i < 50; i++) {
        prime[i] = isPrime(i);
    }
    int n;
    int kase = 0;
    while(scanf("%d", &n) != EOF) {
        kase++;
        if (kase > 1) printf("\n");
        printf("Case %d:\n", kase);
        circle[0] = 1;
        memset(use, 0, sizeof(use));
        use[1] = 1;
        perm(1, n);
    }
    return 0;
}