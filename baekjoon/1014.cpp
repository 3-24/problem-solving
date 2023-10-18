#include <bits/stdc++.h>

using namespace std;


int M, N;
bool blocked[10][10];

int enc(int x, int y){
    return M*x + y;
}

vector<set<int>> bipartite_graph;
vector<int> aMatch, bMatch;
vector<bool> visited;
int asize, bsize;

vector<int> dy = {-1, 0, 1, -1, 0, 1};
vector<int> dx = {-1, -1, -1, 1, 1, 1};

bool dfs(int a){
    if (visited[a]) return false;
    visited[a] = true;
    for (int b=0; b<bsize; b++){
        if (bipartite_graph[a].contains(b)){
            if (bMatch[b] == -1 || dfs(bMatch[b])){
                aMatch[a] = b;
                bMatch[b] = a;

                return true;
            }
        }
    }

    return false;
}

void solve(){
    cin >> M >> N;
    cin.ignore();

    int total_nodes = 0;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            char c;
            cin >> c;
            if (c == 'x'){
                blocked[i][j] = true;
            }
            else{
                assert(c == '.');
                blocked[i][j] = false;
                total_nodes += 1;
            }
        }
        cin.ignore();
    }

    asize = (N/2) * M;
    bsize = (N - N/2) * M;

    bipartite_graph = vector<set<int>>(asize, set<int>());

    for (int i=0; i<M; i++){
        for (int j=1; j<N; j+=2){
            if (blocked[i][j]) continue;

            int x = M * (j / 2) + i;

            for (int k=0; k<6; k++){
                int new_i = i + dy[k];
                int new_j = j + dx[k];
                if (new_i < 0 || new_i >= M) continue;
                if (new_j < 0 || new_j >= N) continue;
                if (blocked[new_i][new_j]) continue;

                int y = M * (new_j / 2) + new_i;
                bipartite_graph[x].insert(y);
            }
        }
    }
    
    // Konig's theorem: maximum bipartite matching is minimum vertex cover
    // Ans is total nodes - minimum vertex cover
    aMatch = vector<int>(asize, -1);
    bMatch = vector<int>(bsize, -1);

    int size = 0;

    for (int start=0; start<asize; start++){
        visited = vector<bool>(asize, false);
        if(dfs(start)) size++;
    }

    cout << total_nodes - size << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin >> C;
    while (C--){
        solve();
    }
}