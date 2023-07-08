#include <bits/stdc++.h>

using namespace std;

int n;
int board[100];
int diagonal_plus_covered[22];
int diagonal_minus_covered[22];

int next(int x, int y){
    if (n % 2 == 1){
        return x + n*y + 2;
    } else {
        if (x == n-1){
            return n * (y+1);
        } else if (x == n-2){
            return n * (y+1) + 1;
        } else {
            return x + n*y + 2;
        }
    }
}

int dfs(int idx){
    if (idx >= n*n) return 0;
    int x = idx % n;
    int y = idx / n;
    if (board[idx] == 0) return dfs(next(x, y));

    // If bishop is not placed
    int v1 = dfs(next(x, y));
    // If bishop is placed

    int minus = x - y + n - 1;
    int plus = x + y;
    
    // Collision with other bishop
    if (diagonal_plus_covered[plus] || diagonal_minus_covered[minus]) return v1;
    else {
        diagonal_plus_covered[plus] = 1;
        diagonal_minus_covered[minus] = 1;
        int v2 = 1 + dfs(next(x, y));
        diagonal_plus_covered[plus] = 0;
        diagonal_minus_covered[minus] = 0;
        return max(v1, v2);
    }
}

int main(){
    cin >> n;

    for (int i=0; i<n*n; i++){
        cin >> board[i];
    }

    cout << dfs(0) + dfs(1);

    return 0;
}