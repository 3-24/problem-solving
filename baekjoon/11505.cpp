#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll mult_inv(ll a, ll b, ll s0 = 1, ll s1 = 0)
{
    return b==0? s0: mult_inv(b, a%b, s1, s0 - s1*(a/b));
}

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end){
    assert(start < end);
    if (start + 1 == end) tree[node] = a[start];
    else {
        int mid = (start + end) / 2;
        init(a, tree, node*2, start, mid);
        init(a, tree, node*2+1, mid, end);
        tree[node] = (tree[node * 2] * tree[node*2+1]) % MOD;
    }
}

ll query(vector<ll> &tree, int node, int start, int end, int left, int right){
    assert(left <= right);
    if (left >= end || right <= start) return 1LL;
    if (start >= left && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    ll lsum = query(tree, node*2, start, mid, left, right);
    ll rsum = query(tree, node*2+1, mid, end, left, right);
    return (lsum * rsum) % MOD;
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff) {
    if (index < start || index >= end) return;
    tree[node] = (tree[node] * diff) % MOD;
    if (start+1 != end) {
        int mid = (start + end) / 2;
        update(tree, node*2, start, mid, index, diff);
        update(tree, node*2+1, mid, end, index, diff);
    }
}

void update_from_zero(vector<ll> &tree, int node, int start, int end, int index, ll val){
    if (index < start || index >= end) return;
    if (start + 1 == end) tree[node] = val;
    else {
        int mid = (start + end) / 2;
        update_from_zero(tree, node*2, start, mid, index, val);
        update_from_zero(tree, node*2+1, mid, end, index, val);
        tree[node] = (tree[node*2] * tree[node*2+1]) % MOD;
    }
}

void update(vector<ll> &a, vector<ll> &tree, int n, int index, ll val){
    if (a[index] == 0){
        a[index] = val;
        update_from_zero(tree, 1, 0, n, index, val);
    } else {
        ll inv = (mult_inv(a[index], MOD) + MOD) % MOD;
        ll diff = (val * inv) % MOD;
        a[index] = val;
        update(tree, 1, 0, n, index, diff);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    int h = ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<ll> tree(tree_size);
    
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    init(a, tree, 1, 0, n);

    m += k;
    while(m--){
        int t1;
        cin >> t1;
        if (t1 == 1){
            int t2;
            ll t3;
            cin >> t2 >> t3;
            t2 -= 1;
            update(a, tree, n, t2, t3);
        } else {
            int t2, t3;
            cin >> t2 >> t3;
            t2 -= 1;
            cout << query(tree, 1, 0, n, t2, t3) << '\n';
        }
    }
}