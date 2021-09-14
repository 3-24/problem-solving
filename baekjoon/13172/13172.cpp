#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long int ll;

ll _aux(ll x, int n){
    if (n == 1) return x;
    ll mult = (n & 1) ? x : 1;
    ll half_aux = _aux(x, n >> 1);
    return (((mult * half_aux) % MOD) * half_aux )% MOD;
}

ll modular_inverse(ll x){
    // x가 0이 아니라고 가정
    return _aux(x, MOD-2);
}

int main(){
    int m;
    cin >> m;
    ll numer = 0;
    ll denom = 1;
    while(m--){
        ll n,s;
        scanf("%lld %lld", &n, &s);
        // (number/denom + s/n)
        ll l = lcm(denom, n);
        numer = ((numer * (l / denom)) % MOD + (s * (l / n)) % MOD) % MOD;
        denom = l % MOD;
    }

    printf("%lld\n", (numer * modular_inverse(denom))%MOD );
    return 0;
}