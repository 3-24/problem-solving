#include <bits/stdc++.h>

using namespace std;

#define fasterio(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    fasterio();
    int n;
    cin >> n;
    vector<int> A(n, 0), B(n, 0);

    auto preprocess = [&](vector<int> &vec){
        for (int i=0; i<n; i++){
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        
        int fst = vec[0];
        for (int i=0; i<n-1; i++){
            vec[i] = vec[i+1] - vec[i];
        }
        vec[n-1] = fst + 360000 - vec[n-1];
    };

    preprocess(A);
    preprocess(B);

    for (int i=0; i<n; i++){
        B.push_back(B[i]);
    }

    // KMP algorithm
    vector<int> pi(n, 0);
    int j = 0;
    for (int i=1; i<n; i++){
        while (j > 0 && A[i] != A[j]){
            j = pi[j-1];
        }
        if (A[i] == A[j]) pi[i] = ++j;
    }

    j = 0;
    
    bool possible = false;
    for (int i=0; i<2*n; i++){
        while (j > 0 && B[i] != A[j]){
            j = pi[j-1];
        }
        if (B[i] == A[j]){
            if (j == n-1){
                possible = true;
                break;
            } else {
                j++;
            }
        }
    }

    if (possible) cout << "possible\n";
    else cout << "impossible\n";

    return 0;
}