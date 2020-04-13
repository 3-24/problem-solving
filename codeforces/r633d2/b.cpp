#include <bits/stdc++.h>
using namespace std;
int64_t arr[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        int i;
        if (n&1) i = n/2;
        else i = n/2 -1;

        for (int j=0;j<n;j++){
            cout << arr[i] << ' ';
            if (j & 1){
                i -= (j+1);
            }
            else{
                i += (j+1);
            }
        }
        cout << '\n';
    }
    return 0;
}
