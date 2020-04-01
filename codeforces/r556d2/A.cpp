#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,r,buy=INT_MAX,sell=0,temp;
    cin >> n >> m >> r;
    for (int i=0;i<n;i++){
        cin >> temp;
        buy = min(temp,buy);
    }
    for (int i=0;i<m;i++){
        cin >> temp;
        sell = max(temp,sell);
    }

    if (buy >= sell) cout << r;
    else{
        int num_shares = r / buy;
        cout << r % buy + sell*num_shares;
    }

    return 0;
}