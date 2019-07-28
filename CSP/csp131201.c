#include <stdio.h>
#include <string.h>

int times[10005];
int main() {
    //freopen("data.in", "r", stdin);
    int n;
    int s;
    scanf("%d", &n);
    memset(times, 0, sizeof(times));
    for (int i = 0; i < n; i++) {
        scanf("%d", &s);
        times[s]++;
    }
    int max = 0;
    int idx = 0;
    for (int i = 1; i < 10001; i++) {
        if (max < times[i]) {
            idx = i;
            max = times[i];
        }
    }
    printf("%d\n", idx);
}