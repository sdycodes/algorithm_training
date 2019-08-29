#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    while(scanf("%d", &n) == 1 && n) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        if(n==1)   {printf("Discarded cards:\nRemaining card: 1\n");continue;}
        printf("Discarded cards: ");
        while(q.size() > 1) {
            printf("%d", q.front());
            q.pop();
            int t = q.front();
            q.pop();
            q.push(t);
            if (q.size() > 1) {
                printf(", ");
            }
        }
        putchar('\n');
        printf("Remaining card: %d\n", q.front());
    }
}