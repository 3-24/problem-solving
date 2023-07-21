#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    // Input processing
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    // Sort arr
    sort(arr, arr+n);

    int i = 0;
    int j = n-1;
    int min_i, min_j, min_abs = INT_MAX;
    while (i < j){
        int min_abs_i = abs(arr[i] + arr[j]);
        while (j-1 > i){
            int new_j = j - 1;
            int a = abs(arr[i] + arr[new_j]);
            if (a < min_abs_i){
                min_abs_i = a;
                j = new_j;
            } else break;
        }

        if (min_abs_i < min_abs){
            min_abs = min_abs_i;
            min_i = i;
            min_j = j;
        }
        i++;
    }

    cout << arr[min_i] << ' ' << arr[min_j] << '\n';
    return 0;
}