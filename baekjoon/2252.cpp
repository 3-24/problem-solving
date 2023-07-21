#include <bits/stdc++.h>

using namespace std;

int in_degree[32001];


// Topological Sort
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<int> graph[n+1];
    for (int i=1; i<=n; i++){
        graph[i] = set<int>();
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        graph[b].insert(a);
    }

    for (int i=1; i<=n; i++){
        for (int j: graph[i]){
            in_degree[j] += 1;
        }
    }

    stack<int> st;

    for (int i=1; i<=n ;i++){
        if (in_degree[i] == 0){
            st.push(i);
        }
    }

    deque<int> sol;

    while(!st.empty()){
        int i = st.top();
        st.pop();
        for (int j: graph[i]){
            in_degree[j] -= 1;
            if (in_degree[j] == 0){
                st.push(j);
            }
        }
        sol.push_front(i);
    }

    for (auto it=sol.begin(); it != sol.end(); it++){
        cout << *it << ' ';
    }
    cout << '\n';
    return 0;
}