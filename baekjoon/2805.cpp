#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll tree[1000001];
int N;
ll M;

ll bisect(ll lo, ll hi){
    if (lo == hi) return lo;
    ll mid = (lo + hi + 1) / 2;
    ll sum = 0;
    for (int i=0; i<N; i++){
        sum += max((ll)0, tree[i]-mid);
    }

    if (sum >= M) return bisect(mid, hi);
    else return bisect(lo, mid-1);
}

int main(){
    cin >> N >> M;
    for (int i=0;i<N;i++){
        cin >> tree[i];
    }
    cout << bisect(0, 2000000000);
    return 0;
}