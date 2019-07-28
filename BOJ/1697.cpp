#include <bits/stdc++.h>
using namespace std;

const int POINT_MAX = 200000;

bool inRange(int n){
    return (0<=n && n <= POINT_MAX);
}

int main(){
    int n,k, cost[POINT_MAX+1] = {0,};
    bool visited[POINT_MAX+1] = {false,};
    list<int> queue;

    cin >> n >> k;

    if (n == k){
        cout << 0;
        return 0;
    }

    else if (n > k){
        cout << n-k;
        return 0;
    }

    else{
        visited[n] = true;
        queue.push_back(n);

        while (!queue.empty()){
            int s = queue.front();
            queue.pop_front();

            int possible_values[3] = {s-1,s+1,s*2};
            int prev_cost = cost[s];

            for (int i=0;i<3;i++){
                int t = possible_values[i];

                if (inRange(t) && !visited[t]){
                    cost[t] = prev_cost + 1;
                    visited[t] = true;
                    queue.push_back(t);

                }

                if (t == k){
                    cout << cost[t];
                    return 0;
                }

            }
        }
    }
}