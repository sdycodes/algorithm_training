#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int a[maxn];

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int min_abs = 20005;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (min_abs > abs(a[i] - a[j])) {
                min_abs = abs(a[i] - a[j]);
            }
        }
    }
    printf("%d\n", min_abs);
    return 0;
}