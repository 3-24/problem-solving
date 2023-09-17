#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000

set<char> seps = {' '};

// S번 - Slice String
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while(N--){
        char c;
        cin >> c;
        seps.insert(c);
    }
    cin >> N;
    while(N--){
        char c;
        cin >> c;
        seps.insert(c);
    }

    cin >> N;
    while (N--){
        char c;
        cin >> c;
        seps.erase(c);
    }

    string s;
    cin >> N;
    cin.ignore();
    getline(cin, s);
    
    bool empty_prev = true;
    for (char c: s){
        if (seps.contains(c)){
            if (!empty_prev){
                cout << '\n';
                empty_prev = true;
            }
        }
        else {
            cout << c;
            empty_prev = false;
        }
    }
    return 0;
}