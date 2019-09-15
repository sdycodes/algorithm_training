#include <cstdio>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 3005;
int a[maxn], l[maxn], r[maxn];
string code[maxn];
struct Node{
    int no;
    int val;
    Node(int no=0, int val=0): no(no), val(val) {}
    bool operator<(const Node &b) const {
        if (val != b.val) return val > b.val;
        return no > b.no;
    }
};

void encoding(int root, string pref) {
    if (l[root] == 0 && r[root] == 0) {
        code[root] = pref;
        return;
    }
    encoding(l[root], pref + '0');
    encoding(r[root], pref + '1');
}
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    int cnt = n + 1;
    priority_queue<Node> q;
    for (int i = 1; i <= n; i++) {
        q.push(Node(i, a[i]));
    }
    while(q.size() > 1) {
        Node u = q.top(); q.pop();
        Node v = q.top(); q.pop();
        l[cnt] = u.no;
        r[cnt] = v.no;
        a[cnt] = u.val + v.val;
        q.push(Node(cnt, a[cnt]));
        cnt++;
    }
    int root = cnt - 1;
    encoding(root, "");
    // for (int i = 1; i <= n; i++) {
    //     printf("%d: %s\n", i, code[i].c_str());
    // }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += code[i].length() * a[i];
    }
    printf("%d\n", res);
    return 0;
}