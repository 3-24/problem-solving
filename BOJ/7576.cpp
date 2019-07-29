#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1000;

pair<int,int> operator + (pair<int,int> a, pair<int,int> b){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m, stat[MAX_SIZE+1][MAX_SIZE+1], day[MAX_SIZE+1][MAX_SIZE+1] = {0,};
    bool visited[MAX_SIZE+1][MAX_SIZE+1] = {false,};

    cin >> n >> m;

    list <pair<int,int>> p,q;
    int count = 0, empty = 0;


    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int t;
            cin >> t;
            stat[i][j] = t;
            if (t == 1){
                q.push_back(make_pair(i,j));
            }
            else if (t == -1) empty++;
        }
    }

    const pair<int,int> ways[4] = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};

    while(!q.empty()){
        pair<int,int> s = q.front();
        q.pop_front();
        if (!visited[s.first][s.second]){
            visited[s.first][s.second] = true;
        }

    }

}
