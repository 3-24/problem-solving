#include <bits/stdc++.h>

using namespace std;

bool left_sum[400001];

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    cin >> w >> n;
    vector<int> arr(n, 0);
    sort(arr.begin(), arr.end());

    for (int i=0; i<n; i++){
        cin >> arr[i]; // <= 5000
    }

    for (int pivot=2; pivot<n-1; pivot++){
        int i1 = pivot - 1;
        for (int i2=0; i2<i1; i2++){
            left_sum[arr[i1] + arr[i2]] = 1;
        }
        for (int i=pivot+1; i<n; i++){
            int value = w - arr[i] - arr[pivot];
            if (value < 0) continue;
            if (value > 400000) continue;
            if (left_sum[value]){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}