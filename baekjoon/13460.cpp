#include <bits/stdc++.h>
using namespace std;

#define MAX_MOVE 10

int n, m;

bool visited[11][11][11][11];

bool move_one(vector<vector<char>> &B, int &x, int &y, int dir){
    if (dir == 0){
        // LEFT
        for (int y0 = y-1; y0>=0; y0--){
            char c = B[x][y0];
            if (c == 'O'){
                B[x][y] = '.';
                x = -1;
                y = -1;
                return true;
            }
            else if (c == '.') continue;
            else {
                swap(B[x][y], B[x][y0+1]);
                y = y0 + 1;
                return false;
            }
        }
    } else if (dir == 2) {
        // RIGHT
        for (int y0 = y+1; y0<m; y0++){
            char c = B[x][y0];
            if (c == 'O'){
                B[x][y] = '.';
                x = -1;
                y = -1;
                return true;
            }
            else if (c == '.') continue;
            else {
                swap(B[x][y], B[x][y0-1]);
                y = y0 - 1;
                return false;
            }
        }        
    } else if (dir == 1) {
        // UP
        for (int x0 = x-1; x0>=0; x0--){
            char c = B[x0][y];
            if (c == 'O'){
                B[x][y] = '.';
                x = -1;
                y = -1;
                return true;
            }
            else if (c == '.') continue;
            else {
                swap(B[x][y], B[x0+1][y]);
                x = x0 + 1;
                return false;
            }
        }
    } else {
        // DOWN
        for (int x0 = x+1; x0<n; x0++){
            char c = B[x0][y];
            if (c == 'O'){
                B[x][y] = '.';
                x = -1;
                y = -1;
                return true;
            }
            else if (c == '.') continue;
            else {
                swap(B[x][y], B[x0-1][y]);
                x = x0 - 1;
                return false;
            }
        } 
    }
    assert(false); // Not reachable
    return false;
}

int move_board(vector<vector<char>> &B, int &rx, int &ry, int &bx, int &by, int dir){
    bool red_succ = false;
    bool blue_succ = false;
    if (dir == 0){
        if (ry < by){
            red_succ = move_one(B, rx, ry, dir);
            blue_succ = move_one(B, bx, by, dir);
        } else {
            blue_succ = move_one(B, bx, by, dir);
            red_succ = move_one(B, rx, ry, dir);
        }
    } else if (dir == 2){
        if (ry > by){
            red_succ = move_one(B, rx, ry, dir);
            blue_succ = move_one(B, bx, by, dir);
        } else {
            blue_succ = move_one(B, bx, by, dir);
            red_succ = move_one(B, rx, ry, dir);
        }
    } else if (dir == 1){
        if (rx < bx){
            red_succ = move_one(B, rx, ry, dir);
            blue_succ = move_one(B, bx, by, dir);
        } else {
            blue_succ = move_one(B, bx, by, dir);
            red_succ = move_one(B, rx, ry, dir);
        }
    } else {
        if (rx > bx){
            red_succ = move_one(B, rx, ry, dir);
            blue_succ = move_one(B, bx, by, dir);
        } else {
            blue_succ = move_one(B, bx, by, dir);
            red_succ = move_one(B, rx, ry, dir);
        }        
    }

    if (blue_succ) return -1;
    else if (red_succ) return 1;
    else return 0;
}



struct QueueElem{
    int count;
    vector<vector<char>> board;
    int rx;
    int ry;
    int bx;
    int by;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<vector<char>> B;
    int rx, ry, bx, by;
    for (int i=0; i<n; i++){
        vector<char> v;
        string s;
        cin >> s;
        for (int j=0; j<m; j++){
            v.push_back(s[j]);
            if (s[j] == 'R'){
                rx = i;
                ry = j;
            } else if (s[j] == 'B'){
                bx = i;
                by = j;
            }
        }
        B.push_back(v);
    }

    queue<QueueElem> Q;
    Q.push(QueueElem(0, B, rx, ry, bx, by));

    // BFS
    while (!Q.empty()){
        QueueElem e = Q.front();
        Q.pop();
        if (visited[e.rx][e.ry][e.bx][e.by]) continue;
        if (e.count == MAX_MOVE) continue;
        visited[e.rx][e.ry][e.bx][e.by] = true;
        int count = e.count + 1;
        for (int dir=0; dir<4; dir++){
            auto Bn(e.board);     // Copy board
            int rxn = e.rx, ryn = e.ry, bxn = e.bx, byn = e.by;
            int res = move_board(Bn, rxn, ryn, bxn, byn, dir);
            if (res == 1){
                cout << count;
                return 0;
            } else if (res == 0){
                if (count < 10){
                    Q.push(QueueElem(count, Bn, rxn, ryn, bxn, byn));
                }
            }
        }
    }
    cout << -1;

    return 0;
}