#include <stdio.h>

int arr[4000][8000];
int star(int height, int x, int y);
int findlength(int height);

int main(){
  int n;
  scanf("%d",&n);
  int m = findlength(n);
  int i,j;
  for (i=1;i<=n;i++){
    for (j=1;j<=m+1;j++){
      if (j == m+1){
        arr[i][j] = '\0';
      }
      else{
        arr[i][j] = ' ';
      }
    }
  }
  star(n,(m+1)/2,1);
  for (i=1;i<=n;i++){
    for (j=1;j<=m;j++){
      printf("%c",arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int star(int height,int x,int y){
  if (height == 3){
    arr[y][x] = '*';
    arr[y+1][x-1] = '*';
    arr[y+1][x+1] = '*';
    arr[y+2][x-2] = '*';
    arr[y+2][x-1] = '*';
    arr[y+2][x] = '*';
    arr[y+2][x+1] = '*';
    arr[y+2][x+2] = '*';
  }
  else{
    star(height/2, x,y);
    star(height/2,x-height/2,y+height/2);
    star(height/2,x+height/2,y+height/2);
  }
}

int findlength(int height){
  if (height == 3){
    return 5;
  }
  else{
    return findlength(height/2)*2 + 1;
  }
}
