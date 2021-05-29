#include <bits/stdc++.h>
using namespace std;

bool solve(int y){
    int i = 0;
    while (111*i <= y){
        if ((y - 111*i) % 11 == 0) return true;
        i++;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int z;
        cin >> z;
        if ( solve(z)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}