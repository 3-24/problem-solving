#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

int main(){
    int n,m,sum=0,number,i,move,temp;
    scanf("%d %d",&n, &m);
    int length = n;
    queue <int> q;
    for (i=1;i<=n;i++){
        q.push(i);
    }
    while(m--){
        scanf("%d",&number);
        move = 0;
        while (q.front() != number){
            temp = q.front();
            q.pop();
            q.push(temp);
            move++;
        }
        q.pop();
        sum += min(length-move,move);
        length--;
    }
    printf("%d",sum);
}