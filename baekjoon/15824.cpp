#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007LL
typedef long long ll;

vector<ll> pow_mod = {1LL};
vector<ll> arr;
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i=1; i<=N; i++){
        pow_mod.push_back((pow_mod.back() << 1) % MOD);
    }

    while (N--){
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    ll count = 0;

    for (int i=0; i<arr.size(); i++){
        int pred = i;
        int succ = arr.size() - 1 - i;
        ll x = arr[i] % MOD;
        count += x * ((pow_mod[pred] - pow_mod[succ]));
        count %= MOD;
    }

    cout << count;
    return 0;
}