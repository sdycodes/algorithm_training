#include <cstdio>
#include <algorithm>

#define DEBUG 0
#define reopen do{if(DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{if(DEBUG) {printf("##DEBUG## ");printf(__VA_ARGS__);printf("\n");}}while(0)

using namespace std;
int a[30005];

int main() {
    reopen;
    int w, n;
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int hi = n - 1;
    while(a[hi] >= w) {
        hi--;
    }
    int lo = 0;
    int cnt = n;
    while(lo < hi) {
        while(lo < hi && a[lo] + a[hi] > w) {
            hi--;
        }
        if (lo < hi) {
            cnt--;
            lo++;
            hi--;
        }
    }
    printf("%d\n", cnt);
    return 0;
}