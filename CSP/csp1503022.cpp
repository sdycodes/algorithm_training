#include <cstdio>
#include <algorithm>

const int maxn = 1005;
struct Elem{
    int num, times;
    Elem(int num = 0, int times=0):num(num), times(times) {}
    bool operator<(const Elem& b) const {
        if (times != b.times) return times > b.times;
        return num < b.num;
    }
};
struct Elem elems[maxn];

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < maxn; i++) {
        elems[i].num = i;
        elems[i].times = 0;
    }
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        elems[t].times++;
    }
    std::sort(elems, elems + maxn);
    for (int i = 0; i < maxn; i++) {
        if (elems[i].times) {
            printf("%d %d\n", elems[i].num, elems[i].times);
        }
    }
    return 0;
}