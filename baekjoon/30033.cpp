#include <bits/stdc++.h>

using namespace std;

// R번 - Rust Study
int A[1000];

int main(){
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    int count = 0;
    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        if (x >= A[i]) count++;
    }

    cout << count;
    return 0;
}