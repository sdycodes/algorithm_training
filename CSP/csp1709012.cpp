#include <cstdio>

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int N;
    scanf("%d", &N);
    printf("%d\n", (N / 50) * 5 + 2 * (N / 50) + ((N % 50)/ 30) * 3 + ((N % 50) / 30) + ((N % 50) % 30) / 10);
    return 0;
}