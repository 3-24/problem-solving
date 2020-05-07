#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int estimate_time(ll n){
    if (n == 0) return 0;
    ll left = 0;
    ll right = 1000000000;
    
    while (right-left != 1){
        ll mid = (left+right)/2;
        ll value = (mid*(mid+1))/2;
        if (value > n) right = mid;
        else left=mid;
    }
    return estimate_time(n-(left*(left+1)/2)) + left;
}


int main(){
    ll n;
    cin >> n;
    cout << estimate_time(n);
    return 0;
}