#include <bits/stdc++.h>
using namespace std;
int64_t arr[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n,x;
        cin >> n >> x;
        int64_t sum=0;
        for (int i=0;i<n;i++){
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr,arr+n);

        int r = 0;
        for (int p=n;p>=1;p--){
            if (sum/((double)p) >= x){
                r = p;
                break;
            }
            sum -= arr[n-p];
        }
        cout << r << '\n';
    }
    return 0;
}
