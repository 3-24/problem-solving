#include <bits/stdc++.h>

using namespace std;
int h,w;
char M[101][101];
bool visited[101][101];

int x_diff[4] = {0, 0, -1, 1};
int y_diff[4] = {-1, 1, 0, 0};

void solve(){
    vector<pair<int,int>> doors[26];
    bool has_key[26] = {0,};
    cin >> h >> w;
    for (int i=0; i<h; i++) {
        cin >> M[i];
        for (int j=0; j<w; j++) {
            char c = M[i][j];
            if ('A' <= c && c <= 'Z'){
                int k = c - 'A';
                doors[k].push_back(pair<int, int>(i, j));
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    string keys_str;
    cin >> keys_str;
    
    for (char c: keys_str){
        if (c == '0') break;
        else {
            int i = c - 'a';
            if (has_key[i] == 0){
                for (auto [r, c]: doors[i]){
                    M[r][c] = '.';
                }
                has_key[i] = 1;
            }
        }
    }

    // Explore each sides
    queue<pair<int, int>> sides;
    stack<pair<int, int>> Q;

    for (int i=0; i<w; i++){
        sides.push(pair<int, int>(0, i));
        sides.push(pair<int, int>(h-1, i));
    }
    for (int i=1; i<h-1; i++){
        sides.push(pair<int, int>(i, 0));
        sides.push(pair<int, int>(i, w-1));
    }

    while (!sides.empty()){
        auto p = sides.front();
        int x = p.first, y = p.second;
        sides.pop();
        if (M[x][y] == '.' || M[x][y] == '$' || ('a' <= M[x][y] && M[x][y] <= 'z')){
            Q.push(p);
        }
    }

    int count = 0;

    while (!Q.empty()) {
        auto [x, y] = Q.top();
        Q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        char c = M[x][y];
        if (c == '$'){
            count += 1;
        } else if ('a' <= c && c <= 'z'){
            int k = c - 'a';
            if (!has_key[k]){
                has_key[k] = true;
                for (auto [x0, y0]: doors[k]){
                    M[x0][y0] = '.';
                    for (int i=0; i<4; i++){
                        int x1 = x0 + x_diff[i];
                        int y1 = y0 + y_diff[i];
                        if (x1 < 0 || x1 >= h || y1 < 0 || y1 >= w || visited[x1][y1]){
                            Q.push(pair<int, int>(x0, y0));
                            break;
                        }
                    }
                }
            }
        }
        for (int i=0; i<4; i++){
            int x1 = x + x_diff[i];
            int y1 = y + y_diff[i];
            if (x1 < 0 || x1 >= h || y1 < 0 || y1 >= w) continue;
            if (M[x1][y1] == '*' || ('A' <= M[x1][y1] && M[x1][y1] <= 'Z')) continue;
            Q.push(pair<int, int>(x1, y1));
        }
    }
    cout << count << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}