#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int r = 31;
    ll M = 1234567891;
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll rs = 1;
    ll sum = 0;
    for (int i=0; i<n; i++){
        sum += (int(s[i]) - 96) * rs;
        sum %= M;
        rs *= r;
        rs  %= M;
    }

    cout << sum;
    return 0;
}