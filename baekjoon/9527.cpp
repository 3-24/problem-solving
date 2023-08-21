#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A, B;

map<ll, ll> count_memory;

int log2(ll x){
    int i = 0;
    while (x != 0){
        x = x >> 1;
        i += 1;
    }
    return i;
}


ll count_one(ll x){
    assert(x >= 0);
    if (count_memory.contains(x)) return count_memory[x];
    
    int l = log2(x);
    ll msb = 1;
    msb = msb << (l-1);


    ll r = (x - msb + 1) + count_one(x - msb) + count_one(msb-1);
    count_memory[x] = r;
    return r;
}

int main(){
    //ios::sync_with_stdio(false);
    count_memory[0] = 0;
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B;
    cout << count_one(B) - count_one(A-1);
}
