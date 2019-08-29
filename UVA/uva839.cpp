#include <iostream>
#include <cstdio>

using namespace std;

struct Node{
    int w;
    int d;
    Node* left, *right;
    Node(int w, int d) {
        this->w = w;
        this->d = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void build_tree(Node* root) {
    int wl, dl, wr, dr;
    scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
    root->left = new Node(wl, dl);
    root->right = new Node(wr, dr);
    if (wl == 0) {
        build_tree(root->left);
    }
    if (wr == 0) {
        build_tree(root->right);
    }
}

bool judge(Node* root) {
    if (root->w != 0) {
        return true;
    }
    bool l = true, r = true;
    if (root->left->w == 0) {
        l = judge(root->left);
    }
    if (root->right->w == 0) {
        r = judge(root->right);
    }
    root->w = root->left->w + root->right->w;
    return l && r && root->left->w * root->left->d == root->right->w * root->right->d;

}

void del_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    del_tree(root->left);
    del_tree(root->right);
    free(root);
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    int first = 1;
    while(T--) {
        if (first) {
            first = 0;
        } else {
            putchar('\n');
        }
        Node* root = new Node(0, 0);
        build_tree(root);
        if (judge(root)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        del_tree(root);
    }
    return 0;
}