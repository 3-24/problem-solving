#include <bits/stdc++.h>

using namespace std;

const int MAX_COMPUTER = 100;
vector<int> network[MAX_COMPUTER+1];
bool visited[MAX_COMPUTER+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int count = 0;
    while (m--){
        int a,b;
        cin >> a >> b;
        network[a].push_back(b);
        network[b].push_back(a);
    }

    list<int> queue;
    queue.push_back(1);

    while (!queue.empty()){
        int e = queue.front();
        queue.pop_front();
        if (!visited[e]){
            count += 1;
            visited[e] = true;
            for (auto x : network[e]){
                queue.push_back(x);
            }
        }
    }

    cout << count - 1;

    return 0;
}
