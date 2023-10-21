#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> x;
    x.push_back(1);
    ll i = 1;
    ll j = 1;
    int count = 0;
    while (true){
        i = j;
        if (count % 4 < 2){
            j += 1;
        } else {
            j += 2;
        }
        if (i * j > n) break;
        x.push_back(i*j);
        count += 1;
    }
    cout << x.size() << '\n';
    for (ll y: x){
        cout << y << ' ';
    }
}