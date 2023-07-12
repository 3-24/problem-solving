#include <bits/stdc++.h>

#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int T, n, m;

// A[i] is prefix sum for A_0 + ... + A_{i-1}
int A[1024];
int B[1024];

map<int, int> sum_count_A;
map<int, int> sum_count_B;

int main(){
    faster

    cin >> T;
    cin >> n;

    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        A[i+1] = A[i] + x;
    }

    cin >> m;
    for (int i=0; i<m; i++){
        int x;
        cin >> x;
        B[i+1] = B[i] + x;
    }

    for (int i=0; i<n; i++){
        for (int j=i+1; j<=n; j++){
            // Sum for a_i + ... + a_{j-1}
            int s = A[j] - A[i];    // (a_0 + ... + a_{j-1}) - (a_0 + ... + a_{i-1})
            if (sum_count_A.contains(s)){
                sum_count_A[s] += 1;
            } else {
                sum_count_A[s] = 1;
            }
        }
    }

    for (int i=0; i<m; i++){
        for (int j=i+1; j<=m; j++){
            int s = B[j] - B[i];
            if (sum_count_B.contains(s)){
                sum_count_B[s] += 1;
            } else {
                sum_count_B[s] = 1;
            }
        }
    }

    long long int r = 0;
    for (auto p: sum_count_A){
        int x = p.first;
        int y = T - x;
        if (sum_count_B.contains(y)){
            r += (long long int) p.second * (long long int) sum_count_B[y];
        }
    }
    cout << r;
    return 0;
}