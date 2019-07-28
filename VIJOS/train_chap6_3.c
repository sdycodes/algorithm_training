#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //freopen("data.in", "r", stdin);
    char valid[1005][257];
    int a[1005];
    int cnt = 0;
    char c;
    int sum = 0;
    while(c = getchar()) {
        if (c == ' ' || c == '\n') {
            a[cnt++] = sum;
            sum = 0;
            if (c == '\n') {
                break;
            }
        } else {
            sum *= 10;
            sum += (c - '0');
        }
    }
    for (int i = 0; i < cnt; i++) {
        scanf("%s", valid[a[i]]);
    }
    for (int i = 1; i <= cnt; i++) {
        printf("%s\n", valid[i]);
    }
    return 0;
}