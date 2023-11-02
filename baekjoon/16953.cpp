#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ll a, b;
    cin >> a >> b;
    map<ll, int> m;
    m[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()){
        ll val = q.front();
        q.pop();
        if (val == b) goto success;
        for (auto i: {val*10 +1, val*2}){
            if (i <= b && i > 0){
                m[i] = m[val] + 1;
                q.push(i);
            }
        }
    }
    cout << "-1\n";
    return 0;
success:
    cout << m[b]+1 << '\n';
    return 0;
}