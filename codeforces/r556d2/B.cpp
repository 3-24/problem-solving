#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int board[51][51],n;

bool check_board(){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (!board[i][j]){
                if (j == 0 || j == n - 1 || i >= n-2) return false;
                if (board[i+1][j-1] + board[i+1][j] + board[i+1][j+1] + board[i+2][j] != 0 ) return false;
                board[i+1][j-1] = 1;
                board[i+1][j] = 1;
                board[i+1][j+1] = 1;
                board[i+2][j] = 1;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> c;
            if (c=='.'){
                board[i][j] = 0;
            }
            else board[i][j] = 1;
        }
    }

    check_board() ? cout << "YES" : cout << "NO";

    return 0;
}