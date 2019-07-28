#include <stdio.h>
#define DEBUG 0
#define reopen do{if(DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{if(DEBUG){printf("##DEBUG## ");printf(__VA_ARGS__);printf("\n");}}while(0)

int main() {
    reopen;
    int rec[1005];
    rec[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        rec[i] = 0;
        for (int j = 1; j <= i / 2; j++) {
            rec[i] += rec[j];
        }
        rec[i]++;
    }
    int n;
    scanf("%d", &n);
    printf("%d\n", rec[n]);
}