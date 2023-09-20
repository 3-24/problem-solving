#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 20;       // Larger than 1000000
int segtree[N*2 + 1];

void modify(int i, int diff){
    // Update leaf
    segtree[N+i] += diff;
    //  for all parent, update the value
    for (i += N; i > 1; i >>= 1){
        segtree[i >> 1] = segtree[i] + segtree[i ^ 1];
    }
}

int query(int i, int rank){
    if (i >= N) return (i - N);
    
    if (segtree[i << 1] > rank) return query(i << 1, rank);
    else return query((i << 1) | 1, rank - segtree[i << 1]);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--){
        int t;
        cin >> t;
        if (t == 1){
            int rank;
            cin >> rank;
            int v = query(1, --rank);
            cout << v+1 << '\n';
            modify(v, -1);
        } else {
            assert(t == 2);
            int v, diff;
            cin >> v >> diff;
            modify(--v, diff);
        }
    }
}