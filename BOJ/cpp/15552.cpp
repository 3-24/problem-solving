#include <iostream>
using namespace std;

int main(){
  cin.tie(NULL);
  cin.sync_with_stdio(false);
  int a,b;
  int n;
  cin >> n;
  for (int i=0;i<n;i++){
    cin >> a >> b;
    cout << a+b << '\n';
  }
  return 0;
}
