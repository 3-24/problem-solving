#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(string s){
    int l = s.length();
    for (int i=0; i<l; i++){
        if (s[i] != s[l-i-1]){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    return;
}

int main(){
    string s;
    while (true){
        cin >> s;
        if (s == "0") break;
        solve(s);
    }
    return 0;
}