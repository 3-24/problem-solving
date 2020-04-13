#include <bits/stdc++.h>
using namespace std;
int arr[100001];

int calc(int n, int i){
    if (i >= n-1) return 0;
    if (arr[i] <= arr[i+1]){        // i <= n-2
        return calc(n, i+1);
    }
    else{ // arr[i] > arr[i+1]
        int c = arr[i] - arr[i+1];
        arr[i+1] = arr[i];
        return max(calc(n, i+1), c);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        int result = calc(n,0);
        int i=0;
        while (1){
            if (result+1 <= (1 << i)) break;
            i++;
        }
        cout << i << '\n';
        
    }
    return 0;
}
