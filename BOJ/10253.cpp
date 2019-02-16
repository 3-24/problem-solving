#include <bits/stdc++.h>
using namespace std;

int getFinalUnitFunction(int a, int b){
    if (!(b % a)) return b/a;
    int x = b/a + 1;
    return getFinalUnitFunction(a*x - b, b*x);
}

void HenryIO(){
    int a,b;
    cin >> a >> b; // a/b
    cout << getFinalUnitFunction(a,b) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) HenryIO();
    return 0;
}