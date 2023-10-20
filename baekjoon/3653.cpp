#include <bits/stdc++.h>

using namespace std;


int n, m;
vector<int> segtree;
vector<int> loc;

void build(){
    for (int i=n+m-1; i>0; --i){
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}

void modify(int p, int diff){
    for (p += m+n; p > 0; p >>= 1){
        segtree[p] += diff;
    }
}

int query(int l, int r){
    int res = 0;
    for (l += m+n, r += m+n; l < r; l >>= 1, r >>= 1){
        if (l & 1) res += segtree[l++];
        if (r & 1) res += segtree[--r];
    }
    return res;
}


void solve(){
    cin >> n >> m;
    segtree = vector<int>(2*(n+m) + 1);
    loc = vector<int>(n, 0);

    int m_count = m;

    for (int i=0; i<n; i++){
        segtree[(m+n)+(m+i)] = 1;
        loc[i] = m+i;
    }

    build();

    for (int i=0; i<m; i++){
        int x;
        cin >> x;
        x -= 1;
        int old_pos = loc[x];
        int new_pos = --m_count;
        loc[x] = new_pos;
        cout << query(0, old_pos) << ' ';
        modify(old_pos, -1);
        modify(new_pos, 1);
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}