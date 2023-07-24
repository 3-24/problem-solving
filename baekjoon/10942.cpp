#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2001];

// 0: Not visited, 1: Not pelindrome, 2: Pelindrome
int8_t dp[2001][2001];

int step(int start, int end){
    if (dp[start][end] == 0){
        if (arr[start] != arr[end-1]){
            dp[start][end] = 1;
        } else {
            dp[start][end] = step(start+1, end-1);
        }
    }
    return dp[start][end];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    cin >> M;

    for (int i=0; i<N; i++){
        dp[i][i] = 2;
        dp[i][i+1] = 2;
    }

    while (M--){
        int x, y;
        cin >> x >> y;
        cout << step(x-1, y) - 1 << '\n';
    }

    
    return 0;
}