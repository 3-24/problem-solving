#include <stdio.h>

int alph_to_num(char c){
  int d = (int)c;
  if (d < 91 ){
    return d - 65;
  }
  else{
    return d - 97;
  }
}

int main(){
  char arr[1000001];
  int count[26];
  scanf("%s",&arr);
  int i = 0;
  for (int j=0;j<26;j++){
    count[i] = 0;
  }
  while(1){
    if (arr[i] == '\0'){
      break;
    }
    else{
      count[alph_to_num(arr[i])] += 1;
    }
    i++;
  }
  int id = 0;
  int temp;
  for (int i=1;i<26;i++){
    if (count[id] < count[i]){
      id = i;
    }
    else if (count[id] == count[i] && count[i] != 0){
      temp = id;
    }
  }
  if (id==temp){
    printf("?");
    return 0;
  }
  printf("%c",id+65);
  return 0;
}
