#include <cstdio>
#include <iostream>
#include <cstring>

#define maxn 100005

using namespace std;

int sum[maxn];

bool build_tree(int pos) {
    int t;
    scanf("%d", &t);
    if (t == -1) {
        return true;
    }
    sum[pos] += t;
    build_tree(pos - 1);
    build_tree(pos + 1);
    return false;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int t;
    int offset = maxn >> 1;
    int kase = 0;
    while(1) {
        kase++;
        memset(sum, 0, sizeof(sum));
        bool null = build_tree(offset);
        if (null) break;
        int p = 0;
        while(!sum[p]) p++;
        printf("Case %d:\n%d", kase, sum[p]);
        for (int i = p + 1; i < maxn; i++) {
            if (sum[i]) {
                printf(" %d", sum[i]);
            }
        }
        printf("\n\n");
        //break;
    }
    return 0;
}