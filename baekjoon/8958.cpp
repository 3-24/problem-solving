#include <stdio.h>

void score(void){
  int count = 0;
  char arr[81];
  int point[81];
  scanf("%s",arr);
  int i = 0;
  while (1){
    if (arr[i] == '\0'){
      point[i] = '\0';
      break;
    }
    else if (arr[i] == 'X'){
      point[i] = 0;
    }
    else if (arr[i] == 'O'){
      if (i == 0){
        point[i] = 1;
      }
      else{
        point[i] = point[i-1] + 1;
      }
    }
    i++;
  }

  for (int j=0;j<i;j++){
    count += point[j];
  }
  printf("%d\n",count);
}

int main(void){
  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    score();
  }
  return 0;
}
