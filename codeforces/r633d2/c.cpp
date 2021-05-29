#include <bits/stdc++.h>
using namespace std;
int arr[100001];

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
        int result = 0;

        for (int i=0;i<n-1;i++){
            int diff = arr[i] - arr[i+1];
            if (arr[i] > arr[i+1]){
                if (result < diff) result = diff;
                arr[i+1] = arr[i];
            }
        }

        int i=0;
        while (1){
            if (result+1 <= (1 << i)) break;
            i++;
        }
        cout << i << '\n';
    }
    return 0;
}
