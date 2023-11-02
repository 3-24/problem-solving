#include <stdio.h>
#include <queue>
#include <utility>  // pair
#include <iostream>
using namespace std;

int map[9][9];
bool visited[9][9];
int n, m;

int evaluate_map();
// 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다.

int solve(int count, int position){
    if (count == 0) return evaluate_map();
    if (position == n*m) return 0;
    int x = position % n;
    int y = position / n;
    if (map[x][y] != 0) return solve(count, position+1);
    else {
        map[x][y] = 1;
        int output = solve(count-1, position+1);
        map[x][y] = 0;
        output = max(output, solve(count, position+1));
        return output;
    }
}

int evaluate_map() {
    int count = 0;
    int count_walls = 0;
    queue<pair<int, int>> q;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            //cerr << map[i][j] << ' ';
            if (map[i][j] == 2){
                q.push({i, j});
                visited[i][j] = true;
                count++;
            }
            else if (map[i][j] == 1) count_walls++;
            else visited[i][j] = false;
        }
        //cerr << '\n';
    }
    //cerr << '\n';
        
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (auto [cx, cy]: vector<pair<int,int>> {{x+1, y}, {x-1, y}, {x, y-1}, {x,y+1}}){
            if (cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
            if (map[cx][cy] != 0) continue;
            if (visited[cx][cy]) continue;
            visited[cx][cy] = true;
            q.push({cx, cy});
            count++;
        }
    }
    //cerr << n*m - count_walls - count << '\n';
    return n*m - count_walls - count;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    printf("%d\n", solve(3, 0));

    return 0;
}
