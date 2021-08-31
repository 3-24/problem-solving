#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

char char_seq[2502];
int dp[2502];

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    faster
    scanf("%s", char_seq);
    int i = 0;
    while (char_seq[i]){
        dp[i] = i;
        i++;
    }
    dp[i] = i;
    for (int midpoint=0; midpoint<i; midpoint++){
        for (int radius = 0; midpoint-radius >=0 && midpoint+radius+1 <= i && char_seq[midpoint-radius] == char_seq[midpoint+radius]; radius++){
            dp[midpoint+radius+1] = min(dp[midpoint+radius+1], dp[midpoint-radius] + 1);
        }
        for (int radius = 0; midpoint-radius >=0 && midpoint+radius+2 <= i && char_seq[midpoint-radius] == char_seq[midpoint+1+radius]; radius++){
            dp[midpoint+radius+2] = min(dp[midpoint+radius+2], dp[midpoint-radius] + 1);
        }
    }
    cout << dp[i];
    return 0;
}