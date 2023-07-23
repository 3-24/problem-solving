#include <bits/stdc++.h>

using namespace std;

int n;
int in_degree[100001];
int points[100001];

void solve(){
    cin >> n;
    memset(in_degree, 0, n * sizeof(int));
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        points[i] = x-1;
        in_degree[x-1] += 1;        // Make zero-index input
    }

    int count = 0;
    stack<int> zero_degree;
    for (int i=0; i<n; i++){
        if (in_degree[i] == 0){
            zero_degree.push(i);
        }
    }

    while (!zero_degree.empty()) {
        int node = zero_degree.top();
        int to = points[node];
        zero_degree.pop();
        count += 1;
        in_degree[to] -= 1;
        if (in_degree[to] == 0){
            zero_degree.push(to);
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
    while (t--){
        solve();
    }
    return 0;
}