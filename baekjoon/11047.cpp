#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[11];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    int count = 0;
    for (int i=n-1; i>=0; i--){
        int v = arr[i];
        if (v > k) continue;
        int num = k / v;
        count += num;
        k -= num * v;
    }
    cout << count;
    return 0;
}