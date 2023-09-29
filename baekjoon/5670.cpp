#include <bits/stdc++.h>

using namespace std;

struct Trie {
    map<char, Trie *> ch;   
    int count;
    
    Trie(){
        count = 0;
    }

    ~Trie(){
        for (auto [_, inner]: ch){
            delete inner;
        }
    }
};

void solve(const int n){
    Trie *root = new Trie;
    Trie *trie_it = root;
    for (int _i=0; _i<n; _i++){
        string s;
        cin >> s;
        for (char c: s){
            if (!trie_it->ch.contains(c)){
                trie_it->ch[c] = new Trie;
            }
            trie_it = trie_it->ch[c];
        }
        trie_it->count += 1;
        trie_it = root;
    }

    queue<pair<Trie *, int>> bfs;
    for (auto [_c, trie_it]: root->ch){
        bfs.push({trie_it, 1});
    }
    int total_count = 0;
    while (!bfs.empty()){
        auto [trie_it, count]= bfs.front();
        bfs.pop();
        total_count += count * trie_it->count;
        int count_inc = (trie_it->count + trie_it->ch.size() > 1) ? 1 : 0;
        for (auto [_ch, trie_next]: trie_it->ch){
            bfs.push({trie_next, count + count_inc});
        }
    }


    cout << fixed << setprecision(2) << float(total_count) / n << '\n';

    delete root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n){
        solve(n);
    }
}