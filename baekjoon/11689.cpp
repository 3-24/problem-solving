#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
set<ll> prime_factor;

int main(){
    cin >> n;
    ll count = n;
    // Get prime factor
    ll p = 2;
    while (p <= sqrt((long double) n)){
        if (n % p != 0){
            p += 1;
        } else {
            prime_factor.insert(p);
            n = n / p;
        }
    }

    if (n != 1) prime_factor.insert(n);
    

    for (ll p: prime_factor){
        count = (count / p) * (p-1);
    }

    cout << count;
    return 0;
}