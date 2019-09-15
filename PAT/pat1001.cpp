#include <cstdio>

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int a, b;
    scanf("%d%d", &a, &b);
    int res = a + b;
    if (res < 0) { 
        res = -res;
        printf("-");
    }
    int dig = 0;
    int digs[20];
    do {
        digs[dig++] = res % 1000;
        res /= 1000;
    } while(res);
    printf("%d", digs[--dig]);
    while(dig > 0) {
        printf(",%03d", digs[--dig]);
    }
    printf("\n");
    return 0;
}