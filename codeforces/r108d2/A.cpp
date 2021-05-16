#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    long long r,b,d;
    while (t--){
        cin >> r >> b >> d;
        if (r > b) swap(r,b);
        if (r * d >= (b-r)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}