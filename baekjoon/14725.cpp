#include <bits/stdc++.h>

using namespace std;

struct Node{
    map<string, Node *> childs;
};

Node arr[150000];
int i;

void print_dfs(Node *x, int depth){
    for (auto [name, y]: x->childs){
        for (int i=0; i<depth*2; i++){
            cout << '-';
        }
        cout << name << '\n';
        print_dfs(y, depth+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    // Allocate root
    Node *root = &arr[0];
    i += 1;

    while (N--){
        int depth;
        cin >> depth;
        Node *node_it = root;
        while (depth--){
            string s;
            cin >> s;
            if (!node_it->childs.contains(s)){
                node_it->childs[s] = &(arr[i++]);
            }
            node_it = node_it->childs[s];
        }
    }

    print_dfs(root, 0);

    return 0;
}