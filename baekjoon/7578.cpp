#include <bits/stdc++.h>

using namespace std;

int segtree[1000001];
int n;

void modify(int i){
    assert(!segtree[n+i]);
    segtree[n+i] = 1;
    for (i += n; i>1; i >>= 1){
        segtree[i >> 1] += 1;
    }
}

int query(int l, int r){
    int res = 0;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l & 1) res += segtree[l++];
        if (r & 1) res += segtree[--r];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    map<int, int> upper_inv;
    vector<int> index_map(n, 0);

    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        upper_inv[x] = i;
    }
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        index_map[upper_inv[x]] = i;
    }

    long long inversion_count = 0;
    for (int i=0; i<n; i++){
        int j = index_map[i];
        inversion_count += query(j+1, n);
        modify(j);
    }

    cout << inversion_count;
}