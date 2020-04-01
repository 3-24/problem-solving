#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
typedef long long ll;
ll resultArr[MAX_N+1];

ll calcPadoban(int x){
    if (resultArr[x] != -1) return resultArr[x];
    resultArr[x] = calcPadoban(x-1) + calcPadoban(x-5);
    return resultArr[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(resultArr,-1,sizeof(ll)*(MAX_N+1));
    ll initArr[] = {0,1,1,1,2,2,3};
    std::copy(initArr,initArr+7,resultArr);
    int t; // 3 <= k <= 500
    cin >> t;
    int inputValue;
    while(t--){
        cin >> inputValue;
        cout << calcPadoban(inputValue) << endl;
    }

    return 0;
}