#include <bits/stdc++.h>
using namespace std;

int64_t A[300000], B[300000];

int solve(){
    int64_t n; // n <= 300000
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> A[i] >> B[i];
    }
    int64_t minval = INT64_MAX;
    int64_t result = 0;
    for (int i=0;i<n;i++){
        int64_t diff = max((int64_t)0,A[i]-B[(i-1+n)%n]);
        result += diff;
        int64_t val = A[i] - diff;
        if (minval >= val){
            minval = val;
        }
    }
    result = result + minval;
    cout << result << '\n';
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}