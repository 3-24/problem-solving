#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1000;
int n,m;
int stat[MAX_SIZE + 1][MAX_SIZE + 1], days[MAX_SIZE + 1][MAX_SIZE + 1] = {0,};
bool visited[MAX_SIZE + 1][MAX_SIZE + 1] = {false,};

pair<int,int> operator + (pair<int,int> a, pair<int,int> b){
    return make_pair(a.first + b.first, a.second + b.second);
}

bool validPair(pair<int, int> x){
    return (0 <= x.first && x.first < n && 0 <= x.second && x.second < m );
}

int main() {

    cin >> m >> n;

    list<pair<int, int>> q;
    int max_days = 0, empty = 0, count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            stat[i][j] = t;
            if (t == 1) {
                q.push_back(make_pair(i, j));
                visited[i][j] = true;
                count++;
            } else if (t == -1) empty++;
        }
    }

    int tomato_n = n * m - empty;

    pair<int, int> ways[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};

    while (!q.empty()) {
        pair<int, int> s = q.front();
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            pair<int, int> d = s + ways[i];

            if (validPair(d) && !visited[d.first][d.second] && stat[d.first][d.second] != -1) {
                visited[d.first][d.second] = true;
                count++;
                q.push_back(d);
                days[d.first][d.second] = days[s.first][s.second] + 1;
                max_days = max(max_days, days[d.first][d.second]);
            }
        }
    }

    if (count == tomato_n) {
        cout << max_days << endl;
    } else cout << -1 << endl;

    return 0;
}
