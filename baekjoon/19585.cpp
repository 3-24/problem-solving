#include <bits/stdc++.h>

using namespace std;

struct Trie{
    map<int, Trie *> children;
    bool is_terminal = false;

    ~Trie(){
        for (auto [_, inner]: children){
            delete inner;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c, n;
    cin >> c >> n;

    Trie *croot = new Trie();
    for (int _i=0; _i<c; _i++){
        Trie *cit = croot;
        string s;
        cin >> s;
        for (char c: s){
            int i = c - 'a';
            if (!cit->children[i]){
                cit->children[i] = new Trie();
            }
            cit = cit->children[i];
        }
        cit->is_terminal = true;
    }

    Trie *nroot = new Trie();
    for (int _i=0; _i<n; _i++){
        Trie *nit = nroot;
        string s;
        cin >> s;
        for (int j=s.size()-1; j>=0; j--){
            int i = s[j] - 'a';
            if (!nit->children[i]){
                nit->children[i] = new Trie();
            }
            nit = nit->children[i];
        }
        nit->is_terminal = true;
    }

    int q;
    cin >> q;
    while (q--){
        string s;
        cin >> s;
        vector<int> color_len;
        Trie *cit = croot;
        for (int i=0; i<s.length(); i++){
            int x = s[i] - 'a';
            if (!cit->children[x]) break;
            cit = cit->children[x];
            if (cit->is_terminal) color_len.push_back(i+1);
        }

        vector<int> nick_len;
        Trie *nit = nroot;
        for (int i=0; i<s.length(); i++){
            int x = s[s.length()-1-i] - 'a';
            if (!nit->children[x]) break;
            nit = nit->children[x];
            if (nit->is_terminal) nick_len.push_back(i+1);
        }

        int nick_len_it = nick_len.size() - 1;
        bool succ = false;
        for (int clen: color_len){
            while (nick_len_it >= 0 && clen + nick_len[nick_len_it] > s.length()){
                nick_len_it -= 1;
            }
            if (nick_len_it == -1) break;
            if (clen + nick_len[nick_len_it] == s.length()){
                succ = true;
                break;
            }
        }
        cout << (succ ? "Yes" : "No") << '\n';
    }
    delete croot;
    delete nroot;
}