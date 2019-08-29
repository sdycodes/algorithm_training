#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int N;
    while(scanf("%d", &N) != EOF && N) {
        int tar[1005];
        while(1) {
            for (int i = 0; i < N; i++) {
                scanf("%d", &tar[i]);
                if (tar[0] == 0) break;
            }
            if (tar[0] == 0) {
                break;
            }
            stack<int> s;
            int pos = 0;
            int front = 1;
            while(1) {
                if (pos < N && front <= N && tar[pos] == front) {
                    pos++;
                    front++;
                } else if (pos < N && !s.empty() && tar[pos] == s.top()) {
                    pos++;
                    s.pop();
                } else if (pos < N && front <= N && tar[pos] != front) {
                    s.push(front);
                    front++;
                } else {
                    break;
                }
            }
            if (pos == N) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        putchar('\n');
    }
    return 0;
}