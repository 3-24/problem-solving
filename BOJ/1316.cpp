#include <stdio.h>

int char_to_int(char c){
  return (int)c-97;
}

int isgroup(void){
  char arr[101];
  int visited[26];
  for (int j=0;j<26;j++){
    visited[j] = 0;
  }
  scanf("%s",&arr);
  int i = 0;
  char c;
  while (arr[i] != '\0'){
    c = arr[i];
    if (visited[char_to_int(c)] == 0){
      while(arr[i] == c){
        i++;
      }
      visited[char_to_int(c)] = 1;
    }
    else{
      return 0;
    }
  }
  return 1;
}

int main(){
  int n;
  int count = 0;
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    count += isgroup();
  }
  printf("%d",count);
  return 0;
}
