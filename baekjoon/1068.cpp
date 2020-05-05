#include <bits/stdc++.h>
using namespace std;

int arr[51];

struct node{
    int parent;
    vector <int> childs;
};

struct node nodes[64];

int dfs_count_leaf(int nidx){
    struct node N = nodes[nidx];
    vector<int>::iterator it;
    if (N.childs.empty()) return 1;
    int count = 0;
    for (it=N.childs.begin();it != N.childs.end();it++){
        count += dfs_count_leaf(*it);
    }
    return count;
}

int main(){
    int n, r;
    int root = -1;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> r;
    for (int i=0;i<n;i++){
        if (i == r) continue;
        int j = arr[i];
        if (j == r) continue;
        if (j == -1){
            root = i;
            continue;
        }
        nodes[j].childs.push_back(i);
    }
    if (root == -1) cout << 0;
    else cout << dfs_count_leaf(root);
    return 0;
}