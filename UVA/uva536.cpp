#include <cstdio>
#include <cstring>

struct TreeNode {
    char v;
    TreeNode *l , *r;
    TreeNode(char v='\0', TreeNode *l=NULL, TreeNode *r=NULL): v(v), l(l), r(r) {}
};

char ps[2000], is[2000];
TreeNode* build(int pl, int pr, int il, int ir) {
    if (pl > pr) return NULL;
    if (pl == pr) {
        return new TreeNode(ps[pl], NULL, NULL);
    }
    int pos = il;
    for (; pos <= ir; pos++) {
        if (is[pos] == ps[pl]) break;
    }
    return new TreeNode(ps[pl], build(pl+1, pl+pos-il, il, pos-1), build(pl+pos-il+1, pr, pos+1, ir));
}
void post_order(TreeNode* u) {
    if (u == NULL) return;
    post_order(u->l);
    post_order(u->r);
    putchar(u->v);
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    while(scanf("%s%s", ps, is) != EOF) {
        TreeNode* root = build(0, strlen(ps) - 1, 0, strlen(is) - 1);
        post_order(root);
        putchar('\n');
    }
    return 0;
}