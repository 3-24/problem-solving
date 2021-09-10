#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, bomb;
    cin >> s;
    cin >> bomb;
    deque<int> bomb_indices;
    int bomb_index = 0;
    bool is_empty = true;
    for (int i=0; i<s.length(); i++){
        if (s[i] == bomb[bomb_index]){
            bomb_indices.push_back(bomb_index);
            bomb_index += 1;
        }
        else if (s[i] == bomb[0]){
            bomb_indices.push_back(0);
            bomb_index = 1;
        }
        
        else {
            if (!bomb_indices.empty()){
                for (auto i: bomb_indices){
                    cout << bomb[i];
                }
                bomb_indices.clear();
                bomb_index = 0;
            }
            cout << s[i];
            is_empty = false;
            continue;
        }

        if (bomb_index == bomb.length()){
            for (int j=0; j<bomb.length(); j++){
                bomb_indices.pop_back();
            }
            if (bomb_indices.empty()){
                bomb_index = 0;
            }
            else {
                bomb_index = bomb_indices.back()+1;
            }
        }
    }
    if (!bomb_indices.empty()){
        is_empty = false;
        for (auto i: bomb_indices){
            cout << bomb[i];
        }
    }
    if (is_empty) cout << "FRULA";
    cout << "\n";
    return 0;
}