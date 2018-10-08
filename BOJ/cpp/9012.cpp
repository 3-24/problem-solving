#include <stdio.h>

int check(char arr[]){
  int i = 0, sum = 0;
  char c = arr[i];
  while (c != '\0'){
    c == '(' ? sum++ : sum-- ;
    if (sum < 0){
      return 0;
    }
    i++;
    c = arr[i];
  }
  return sum == 0? 1:0 ;
}

int main(){
  char arr[51];
  int T;
  scanf("%d",&T);
  while(T--){
    int i = 0;
    scanf("%s",&arr);
    check(arr) ? printf("YES\n") : printf("NO\n");
  }
}
