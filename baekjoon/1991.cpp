#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node {
    char value;
    node *left;
    node *right;
};

void print_nodes(vector<node *> v) {
    for (auto n : v) {
        putchar(n->value);
    }
    putchar('\n');
    return;
}

void dfs_preorder(node *v, vector<node *> *record) {
    if (v == NULL) return;
    record->push_back(v);
    dfs_preorder(v->left, record);
    dfs_preorder(v->right, record);
    return;
}

void dfs_inorder(node *v, vector<node *> *record) {
    if (v == NULL) return;
    dfs_inorder(v->left, record);
    record->push_back(v);
    dfs_inorder(v->right, record);
    return;
}

void dfs_postorder(node *v, vector<node *> *record) {
    if (v == NULL) return;
    dfs_postorder(v->left, record);
    dfs_postorder(v->right, record);
    record->push_back(v);
    return;
}

int main() {
    int n;
    cin >> n;
    node nodes[40];
    node *root_node;
    for (int i = 0; i < n; i++) {
        char x, y, z;
        cin >> x >> y >> z;
        int xi = int(x) - 65;
        int yi = int(y) - 65;
        int zi = int(z) - 65;
        nodes[xi].value = x;
        if (yi != -19) {
            nodes[xi].left = &(nodes[yi]);
        } else
            nodes[xi].left = NULL;
        if (zi != -19) {
            nodes[xi].right = &(nodes[zi]);
        } else
            nodes[xi].right = NULL;

        if (x == 'A') root_node = &nodes[xi];
    }

    vector<node *> preorder, inorder, postorder;
    dfs_preorder(root_node, &preorder);
    print_nodes(preorder);
    dfs_inorder(root_node, &inorder);
    print_nodes(inorder);
    dfs_postorder(root_node, &postorder);
    print_nodes(postorder);
    return 0;
}