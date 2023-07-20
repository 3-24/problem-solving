#include <bits/stdc++.h>

using namespace std;

void dfs(int board[], int i){
    if (i == 81){
        for (int j = 0; j < 81; j++){
            cout << board[j];
            if (j % 9 == 8) cout << '\n';
        }
        exit(0);
        return;
    }

    if (board[i] != 0){
        dfs(board, i+1);
        return;
    } else {
        bool used[10] = {false, };
        int row = i / 9;
        int col = i % 9;
        int block_x = (row / 3) * 3;
        int block_y = (col / 3) * 3;

        for (int j=0; j<9; j++){
            used[board[row*9 + j]] = true;
            used[board[j*9 + col]] = true;
            int block_inc_x = j / 3;
            int block_inc_y = j % 3;
            used[board[(block_x + block_inc_x) * 9 + block_y + block_inc_y]] = true;
        }

        for (int v=1; v<=9; v++){
            if (used[v]) continue;
            board[i] = v;
            dfs(board, i+1);
            board[i] = 0;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sudoku[81];
    int i = 0;
    while (i < 81){
        char c;
        cin >> c;
        if (c == '\n') continue;
        else sudoku[i] = c - '0';
        i += 1;
    }

    dfs(sudoku, 0);

    return 0;
}