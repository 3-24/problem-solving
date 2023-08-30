#include <bits/stdc++.h>

using namespace std;

multiset<int> L;     // Red-Black Tree

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    int x;

    // mlog(m)
    while (m--){
        cin >> x;
        L.insert(x);
    }

    // k(log(m)+log(m))
    while (k--){
        cin >> x;
        auto it = L.upper_bound(x);
        cout << *it << '\n';
        L.erase(it);
    }
    return 0;
}