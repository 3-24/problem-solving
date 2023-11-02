#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; // 1 <= n <= 100, 1 <= k <= 10000
    cin >> n >> k;
    vector<int> Value;
    int resultArr[10001] = {1,};
    int t;
    for (int i=0;i<n;i++){
        cin >> t;
        Value.push_back(t);
    }
    for (auto i:Value){
        for (int j=i;j<=k;j++){
            resultArr[j] += resultArr[j-i];
        }
    }
    cout << resultArr[k];
    return 0;
}