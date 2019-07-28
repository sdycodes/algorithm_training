#include <cstdio>
#include <queue>
#include <vector>

#define DEBUG 0
#define reopen do{if (DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{if (DEBUG) {printf("##DEBUG## "); printf(__VA_ARGS__);printf("\n");}}while(0)
using namespace std;

int main() {
    reopen;
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    scanf("%d", &n);
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        q.push(tmp);
    }
    int res = 0;
    while(q.size() != 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        res += (a + b);
        q.push(a + b);
    }
    printf("%d\n", res);

}