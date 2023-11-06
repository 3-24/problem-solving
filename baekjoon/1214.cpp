#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll D, P, Q;
    cin >> D >> P >> Q;
    if (P > Q) swap(P, Q);
    ll min_payed = INT64_MAX;
    set<ll> payed;

    ll p_sum = ((D+P-1) / P) * P;
    ll q_sum = 0;
    
    while (true){
        ll n = p_sum + q_sum;
        if (payed.contains(n)) break;
        min_payed = min(min_payed, n);
        payed.insert(n);
        if (p_sum == 0) break;
        q_sum += Q;
        p_sum = max(((D - q_sum + P - 1) / P) * P, 0ll);
    }

    cout << min_payed << '\n';
}