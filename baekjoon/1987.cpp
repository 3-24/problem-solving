#include <bits/stdc++.h>
using namespace std;

int r, c;
char board[21][21];
int visited[26];

const int x_change[] = {-1, 1, 0, 0};
const int y_change[] = {0, 0, -1, 1};

int explore(int x, int y){
    int count = 0;
    for (int i=0; i< 4; i++){
        int new_x = x + x_change[i];
        int new_y = y + y_change[i];
        if (0<= new_x && new_x < r &&  0 <= new_y && new_y < c){
            int new_alph = board[new_x][new_y];
            if (visited[new_alph] == 0){
                visited[new_alph] = 1;
                count = max(explore(new_x, new_y)+1, count);
                visited[new_alph] = 0;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for (int ri=0; ri<r; ri++){
        cin >> board[ri];
    }

    for (int ri=0; ri<r; ri++){
        for (int ci=0; ci<c; ci++){
            board[ri][ci] -= 'A';
        }
    }

    visited[board[0][0]] = 1;

    cout << 1 + explore(0, 0);
    return 0;
}