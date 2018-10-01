#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
  int p = strlen((char *)a),q = strlen((char *)b);
  if (p != q){
    return p-q;
  }
  else return strcmp((char *)a, (char *)b);
}

int main(){
  int n;
  scanf("%d",&n);
  char words[n][51];
  for (int i=0;i<n;i++){
    scanf("%s",words[i]);
  }
  qsort(words,n,sizeof(words[0]),compare);
  int i=0,j;
  while (i < n){
    printf("%s\n",words[i]);
    j = i;
    do{i++;}
    while (strcmp(words[i],words[j])==0);
  }
}
