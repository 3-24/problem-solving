#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isNumber (const string& str){
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;  
}

int main(){
    int n, m;
    cin >> n >> m;
    string arr[100001];
    map<string, int> map_;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        arr[i] = s;
        map_[s] = i;
    }
    for (int i=0; i<m; i++){
        string s;
        cin >> s;
        if (isNumber(s)){
            int x = stoi(s);
            cout << arr[x-1] << '\n';
        }
        else cout << map_[s]+1 << '\n';
    }
    return 0;
}