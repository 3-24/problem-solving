#include <stdio.h>

int room(int h, int w, int n){
  n--;
  int a = n/h;
  int b = n%h;
  return 100*(b+1) + (a+1);
}

int main(){
  int T;
  scanf("%d",&T);
  int H,W,N;
  for (int i=0;i<T;i++){
    scanf("%d %d %d",&H,&W,&N);
    printf("%d\n",room(H,W,N));
  }
}
