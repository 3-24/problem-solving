#include <bits/stdc++.h>

using namespace std;

#define MATRIX_MAX 1000
#define MOD 10

int n, m;

bool Mat[MATRIX_MAX][MATRIX_MAX];
int parent[MATRIX_MAX*MATRIX_MAX];
int _size[MATRIX_MAX*MATRIX_MAX];
int x_diff[4] = {1, -1, 0, 0};
int y_diff[4] = {0, 0, 1, -1};


int encode(int x, int y){
    return m*x + y;
}

int find(int x){
    if (parent[x] < 0) return x;
    int y = find(parent[x]);
    parent[x] = y;
    return y;
}

void _union(int x, int y){
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (parent[x] < parent[y]){
        parent[y] = x;
        _size[x] += _size[y];
        _size[x] %= MOD;
    } else {
        if (parent[x] == parent[y]){
            parent[y] -= 1;
        } 
        parent[x] = y;
        _size[y] += _size[x];
        _size[y] %= MOD;
    }
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int j=0; j<m; j++){
            Mat[i][j] = (s[j] == '1') ? 1 : 0;
        }
    }

    for (int i=0; i<m*n; i++){
        parent[i] = -1;
        _size[i] = 1;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!Mat[i][j]){
                if (i != 0 && !Mat[i-1][j]){
                    _union(encode(i, j), encode(i-1, j));
                }
                if (j != 0 && !Mat[i][j-1]){
                    _union(encode(i,j), encode(i, j-1));
                }
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!Mat[i][j]){
                cout << '0';
            } else {
                set<int> roots;
                for (int k=0; k<4; k++){
                    int new_i = i + x_diff[k];
                    int new_j = j + y_diff[k];
                    if (0<= new_i && new_i < n && 0 <= new_j && new_j < m && !Mat[new_i][new_j]){
                        roots.insert(find(encode(new_i, new_j)));
                    }
                }
                int s = 1;
                for (int x: roots){
                    s += _size[x];
                }
                cout << s % MOD;
            }
        }
        cout << '\n';
    }
}