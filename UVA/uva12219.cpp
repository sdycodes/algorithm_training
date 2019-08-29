#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;

string s;
int pos;

const int maxn = 50005;
int ncnt;
int done[maxn];

struct Node{
    string name;
    int hash, left, right;
    // 技巧1 使用hash可以提高map中比较的速度
    bool operator<(const Node& rhs) const {
        if (hash != rhs.hash) return hash < rhs.hash;
        if (left != rhs.left) return left < rhs.left;
        return right < rhs.right; 
    }
}nodes[maxn];

map<Node, int> tree2no;

int parse() {
    int num = ncnt++;
    Node &u = nodes[num];
    // caculate hash
    int l = pos;
    int len = 0;
    int hash = 0;    
    while(s[pos] >= 'a' && s[pos] <= 'z') {
        hash = hash * 27 + (s[pos] - 'a' + 1);
        len++;
        pos++;
    }
    u.hash = hash;
    u.name = s.substr(l, len);
    u.left = u.right = 0;
    // 一遍扫描式 构树  利用字符串界定符特性
    if (s[pos] == '(') {  // ROOT(L, R)
        pos++;
        u.left = parse();
        pos++;
        u.right = parse();
        pos++;
    }
    // 注意map中如果key是结构体 需要定义operator 只要字段的值是一样的 就认为是同一个对象
    //但是这里为了修改结构体的值 本来就是传引用 所以没问题
    if (tree2no.find(nodes[num]) != tree2no.end()) {
        // 这种情况一定是最后一个不用担心中间编号的错乱 因为子表达式相同只可能是和左下角相同
        // 那么中序遍历只=中一定是先出现的
        num--; ncnt--;
        return tree2no[nodes[num + 1]];
    }
    return tree2no[nodes[num]] = num;
}

void print(int u) {
    if (done[u] == 1) {
        cout << u;
        return;
    } 
    done[u] = 1;
    cout << nodes[u].name;
    if (nodes[u].left == 0) return;
    cout << "(";
    print(nodes[u].left);
    cout << ",";
    print(nodes[u].right);
    cout << ")";
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    //ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        cin >> s;
        tree2no.clear();
        ncnt = 1;
        memset(done, 0, sizeof(done));
        pos = 0;
        print(parse());
        cout << "\n";
    } 
    return 0;
}