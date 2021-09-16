#include <bits/stdc++.h>
using namespace std;

#define MAX_LOCATION 100000

bool visited[MAX_LOCATION+1];
queue<int> q;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    if (n >= k){
        printf("%d\n", n-k);
    }
    else{
        int m = n;
        while (m <= MAX_LOCATION){
            visited[m] = true;
            q.push(m);
            if (m == 0) break;
            m <<= 1;
        }
        int time = 0;
        while (!visited[k]){
            int q_size = q.size();
            while (q_size--){
                int x = q.front();
                q.pop();
                for (int next: {x-1, x+1}){
                    if (next < 0 || next > MAX_LOCATION || visited[next]) continue;
                    int _next = next;
                    while (_next <= MAX_LOCATION && !visited[_next]) {
                        visited[_next] = true;
                        q.push(_next);
                        if (_next == 0) break;
                        _next <<= 1;
                    }
                }
            }
            time++;
        }

        printf("%d\n", time);
    }
    
    return 0;
}