#include <stdio.h>
#include <queue>
#include <set>
using namespace std;

int main(){
    int n,m,v;
    scanf("%d %d %d",&n,&m,&v);
    queue <int> q;
    set <int> visited;
    visited.insert(v);
    int count = 1;
    int arr[n+1][n+1];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            arr[i][j] = 0;
        }
    }
    int a,b;
    while (m--){
        scanf("%d %d",&a,&b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    while (count < n){

    }
}