#include <stdio.h>

#define DEBUG 0
#define reopen do{if(DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{if(DEBUG) {printf("##DEBUG## ");printf(__VA_ARGS__);printf("\n");}}while(0)

int main() {
    reopen;
    int N;
    scanf("%d", &N);
    int a[100];
    int sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int target = sum / N;
    int pre = 0;
    int res = 0;
    for (int i = 0; i < N; i++) {
        int cur = a[i] + pre;
        if (cur != target) {
            res++;
        } 
        pre = cur - target;
    }
    printf("%d\n", res);
    return 0;
}

