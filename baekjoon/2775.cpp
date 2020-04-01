#include <stdio.h>

int adj[16][16];

int room(int fl,int num){
  if (adj[fl][num] == 0){
    int i;
    for (i=1;i<=num;i++){
      adj[fl][num] += room(fl-1,i);
    }
  }
  return adj[fl][num];
}

int main(){
  for (int i=0;i<15;i++){
    for (int j=1;j<15;j++){
      if (i == 0){
        adj[i][j] = j;
      }
      else{
        adj[i][j] = 0;
      }
    }
  }
  int T;
  int k,n;
  scanf("%d",&T);
  for (int i=0;i<T;i++){
    scanf("%d",&k);
    scanf("%d",&n);
    printf("%d\n",room(k,n));
  }
}
