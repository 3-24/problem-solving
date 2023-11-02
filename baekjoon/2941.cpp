#include <stdio.h>

int checkcroatic(int n, char a[]){
  if (a[n] == 'c'){
    if (a[n+1] == '=' || a[n+1] == '-'){
      return 2;
    }
  }
  else if (a[n] == 'd'){
    if (a[n+1] == 'z' && a[n+2] == '='){
      return 3;
    }
    else if (a[n+1] == '-'){
      return 2;
    }
  }
  else if (a[n] == 'l' && a[n+1] == 'j'){
    return 2;
  }
  else if (a[n] == 'n' && a[n+1] == 'j'){
    return 2;
  }
  else if (a[n] == 's' && a[n+1] == '='){
    return 2;
  }
  else if (a[n] == 'z' && a[n+1] == '='){
    return 2;
  }
  return 1;
}

int main(){
  char arr[105];
  scanf("%s", arr);
  int count = 0;
  int i = 0;
  while (arr[i] != '\0'){
    int add = checkcroatic(i,arr);
    i += add;
    count++;
  }
  printf("%d",count);
  return 0;
}
