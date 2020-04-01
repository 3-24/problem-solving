#include <stdio.h>
#include <queue>
#define MAX_VALUE 1001
using namespace std;

int n,m,v;
int graph[MAX_VALUE][MAX_VALUE];
int visited[MAX_VALUE];

void initGraph(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            graph[i][j] = 0;
        }
    }
}

void initVisited(){
    for (int i=1;i<=n;i++){
        visited[i] = 0;
    }
}

void dfs(int node){
    printf("%d",node);
    visited[node] = 1;
    for (int i=1;i<=n;i++){
        if (graph[node][i] && (!visited[i])){
            printf(" ");
            dfs(i);
        }
    }

}

int main(){
    scanf("%d %d %d",&n,&m,&v);
    initGraph();
    initVisited();
    int a,b;
    while (m--){
        scanf("%d %d",&a,&b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    //DFS
    dfs(v);
    printf("\n");
    //BFS
    queue <int> plan;
    plan.push(v);
    initVisited();
    visited[v] = 1;
    int node;
    while (1){
        node = plan.front();
        printf("%d",node);
        plan.pop();
        for (int i=1;i<=n;i++){
            if (graph[node][i] && (!visited[i])){
                plan.push(i);
                visited[i] = 1;

            }
        }
        if (plan.empty()){
            break;
        }
        printf(" ");
    }
}