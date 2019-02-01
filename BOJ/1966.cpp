#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;
#define MAX_PAPER 100

int compare(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int main(){
    int test_num, value[MAX_PAPER+1];
    scanf("%d",&test_num);
    int n,m,v;
    while(test_num--){
        queue <int> q;
        scanf("%d %d",&n,&m); // n<=100, 0<=m<n
        for (int i=0;i<n;i++) {
            scanf("%d", &v);
            q.push(v);
            value[i] = v;
        }
        qsort(value,n,sizeof(int),compare);
        int length = n, index = m, count = 0;
        while(1){
            if (value[count] == q.front()){
                length--;
                q.pop();
                count++;
                if (!index) break;
                index--;
            }
            else{
                q.push(q.front());
                q.pop();
                if (!index){
                    index = length-1;
                }
                else{
                    index--;
                }
            }
        }
        printf("%d\n",count);
    }
}