#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007
#define MAX_N 4000000

ll mult_inv_(ll a, ll b, ll s0 = 1, ll s1 = 0)
{
    return b==0? s0: mult_inv_(b, a%b, s1, s0 - s1*(a/b));
}

ll mult_inv(ll a){
    return (mult_inv_(a, MOD) + MOD) % MOD;
}

vector<ll> fact;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fact.push_back(1);
    for (int n=1; n<=MAX_N; n++){
        fact.push_back((fact[n-1] * n) % MOD);
    }
    int M;
    cin >> M;
    for (int _=0; _<M; _++){
        int N, K;
        cin >> N >> K;
        
        ll res = (fact[N] * mult_inv(fact[N-K])) % MOD;
        res = (res * mult_inv(fact[K])) % MOD;
        cout << res << '\n';
    }
}