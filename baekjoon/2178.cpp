#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100

char maze[MAX_SIZE+1][MAX_SIZE+1];
int n,m;

std::pair<int, int> operator +(const std::pair<int, int>& x, const std::pair<int, int>& y) {
    return std::make_pair(x.first + y.first, x.second + y.second);
}

bool validBound(const pair<int, int>& x){
    int a= x.first;
    int b = x.second;
    return ((0 <= a && a < n ) && (0 <= b && b < m));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i=0;i<n;i++){
        cin >> maze[i];
    }

    if (n == 1 && m == 1){
        cout << 1;
        return 0;
    }

    bool visited[MAX_SIZE+1][MAX_SIZE+1] = {false,};
    int cost[MAX_SIZE+1][MAX_SIZE+1] = {0,};
    cost[0][0] = 1;

    visited[0][0] = true;
    list<pair<int,int>> queue;
    queue.push_back(make_pair(0,0));
    pair <int,int> ways[4] = {make_pair(-1,0), make_pair(1,0), make_pair(0,-1), make_pair(0,1)};

    while (!queue.empty()){
        pair<int,int> s = queue.front();
        queue.pop_front();
        int level = cost[s.first][s.second];

        for (int i=0;i<4;i++){
            pair <int,int> dest = s + ways[i];
            if (validBound(dest)){
                if (maze[dest.first][dest.second] == '1' && !visited[dest.first][dest.second]){
                    if (dest.first == n-1 && dest.second == m-1){
                        cout << level + 1;
                        return 0;
                    }
                    visited[dest.first][dest.second] = true;
                    queue.push_back(dest);
                    cost[dest.first][dest.second] = level +1;
                }
            }
        }
    }

    return 0;
}