#include <stdio.h>
#include <stack>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  char result[3*n+100000];
  int arr[n+3];
  for (int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  arr[n+1] = -1;
  stack <int> s;
  int i = 1, status = 1, resultIndex = 0;

  while(1){
    if (!s.empty() && arr[status] == s.top()){
      s.pop();
      result[resultIndex] = '-';
      resultIndex++;
      status++;
    }
    else if (i<=n){
      s.push(i);
      result[resultIndex] = '+';
      resultIndex++;
      i++;
    }
    else{
      break;
    }
  }

  if (status > n){
    for (int j=0;j<resultIndex;j++){
      printf("%c\n",result[j]);
    }
  }
  else{
    printf("NO");
  }

  return 0;
}
