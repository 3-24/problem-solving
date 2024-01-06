#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    
    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    i64 res = 0;

    for (int i=0; i<N; i++){
        res ^= (i64)A[i] * (i64)A[i];
        if (i != 0) res ^= (i64) A[i] * (i64) A[i-1];
    }

    cout << res;
    return 0;
}