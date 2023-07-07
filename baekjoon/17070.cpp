#include <bits/stdc++.h>
using namespace std;

int n; // 3 <= n <= 16
int MAP[17][17];
// Direction 0: horizontal, 1: vertical, 2: diagonal
int dp[17][17][3];

int dp_update(int x, int y, int dir){
    if (dp[y][x][dir] != 0) return dp[y][x][dir];
    if (dir == 0){
        if (x == 0 || MAP[y][x] == 1){
            return dp[y][x][dir];
        } else {
            dp[y][x][dir] = dp_update(x-1, y, 0) + dp_update(x-1, y, 2);
        }
    } else if (dir == 1){
         if (y == 0 || MAP[y][x] == 1){
            return dp[y][x][dir];
        } else {
            dp[y][x][dir] = dp_update(x, y-1, 1) + dp_update(x, y-1, 2);
        }       
    } else {
        if (x == 0 || y == 0 || MAP[y][x] == 1 || MAP[y-1][x] == 1 || MAP[y][x-1] == 1){
            return dp[y][x][dir];
        } else {
            dp[y][x][dir] = dp_update(x-1, y-1, 2) + dp_update(x-1, y-1, 1) + dp_update(x-1, y-1, 0);
        }
    }
    return dp[y][x][dir];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> MAP[i][j];
        }
    }

    dp[0][1][0] = 1;

    cout << dp_update(n-1, n-1, 0) + dp_update(n-1, n-1, 1) + dp_update(n-1, n-1, 2);

    return 0;
}