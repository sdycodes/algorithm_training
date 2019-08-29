#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

#define maxn 10005

using namespace std;

int in[maxn], post[maxn];
int lch[maxn], rch[maxn];

int build_tree(int il, int ir, int pl, int pr) {
    if (il > ir || pl > pr) {
        return 0;
    }
    int root = post[pr];
    int pos = il;
    while(pos <= ir && in[pos] != root) {
        pos++;
    }
    lch[root] = build_tree(il, pos - 1, pl, pl + pos - il - 1);
    rch[root] = build_tree(pos + 1, ir, pl + pos - il, pr - 1);
    return root;
}

void dfs(int root, int& val, int& terminal) {
    int vl = -1, tl = -1, vr = -1, tr = -1;
    if (lch[root]) {
        dfs(lch[root], vl, tl);
    }
    if (rch[root]) {
        dfs(rch[root], vr, tr);
    }
    if (vl == -1 && vr == -1) {
        val = root;
        terminal = root;
    }
    if (vl == -1 && vr != -1) {
        val = vr + root;
        terminal = tr;
    }
    if (vl != -1 && vr == -1) {
        val = vl + root;
        terminal = tl;
    }
    if (vl != -1 && vr != -1) {
        if (vl < vr) {
            val = vl + root;
            terminal = tl;
        } else if (vr < vl) {
            val = vr + root;
            terminal = tr;
        } else {
            terminal = min(tl, tr);
        }
    }
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    string ins, posts;
    while(getline(cin, ins)) {
        getline(cin, posts);
        stringstream buf(ins);
        int t;
        int cnt = 1;
        while (buf >> in[cnt]) {
            cnt++;
        }
        cnt = 1;
        stringstream buf2(posts);
        while(buf2 >> post[cnt]) {
            cnt++;
        }
        //build_tree
        int root = build_tree(1, cnt - 1, 1, cnt - 1);
        //dfs search
        int val, terminal;
        dfs(root, val, terminal);
        //output
        printf("%d\n", terminal);
    }
    return 0;
}