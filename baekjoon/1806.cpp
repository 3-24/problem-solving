#include <bits/stdc++.h>

#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, s;



long long int arr[100000];

int main(){
    faster
    cin >> n >> s;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    int start = 0;
    int end = 0;
    long long int sum = 0;
    int min_length = INT_MAX;
    bool success = false;
    bool stop_cond = false;
    

    while (start < n || stop_cond){
        while(sum < s){
            sum += arr[end++];
            if (end == n+1){
                stop_cond = true;
                break;
            }
        }
        if (stop_cond) {
            break;
        }
        success = true;
        min_length = min(min_length, end - start);
        sum -= arr[start++];
    }

    if (!success) cout << 0;
    else cout << min_length;
    return 0;
}