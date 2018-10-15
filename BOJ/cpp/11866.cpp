#include <stdio.h>
#include <queue>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    queue <int> q;
    for (int i=1;i<=n;i++){
        q.push(i);
    }
    int temp, count = 0, arr[n+1];
    while (!q.empty()){
        for (int i=1;i<=m;i++){
            temp = q.front();
            q.pop();
            if (i==m){
                arr[count] = temp;
            }
            else q.push(temp);
        }
        count++;
    }
    printf("<");
    for (int i=0;i<n;i++){
        printf("%d",arr[i]);
        if (i<n-1) {
            printf(", ");
        }
    }
    printf(">");
    return 0;
}