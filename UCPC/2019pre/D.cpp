#include <bits/stdc++.h>

using namespace std;

struct Trie {
    bool finish;    //끝나는 지점을 표시해줌
    long long count;
    Trie* next[26];    //26가지 알파벳에 대한 트라이

    Trie() {
        finish = false;
        memset(next, 0, sizeof(next));
        count = 1;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i]) delete next[i];
    }

    void insert(const char* key) {
        if (*key == '\0')
            finish = true;    //문자열이 끝나는 지점일 경우 표시
        else {
            int curr = *key - 'a';
            if (next[curr] == NULL) {
                next[curr] = new Trie();    //탐색이 처음되는 지점일 경우 동적할당
            }
            else (*next[curr]).count += 1;
            next[curr]->insert(key + 1);    //다음 문자 삽입
        }
    }

    Trie* find(const char* key, int cnt) {
        if (!cnt) return this;//문자열이 끝나는 위치를 반환
        int curr = *key - 'a';
        if (next[curr] == NULL) return NULL;//찾는 값이 존재하지 않음
        return next[curr]->find(key + 1, cnt - 1); //다음 문자를 탐색
    }

};

#define MAX_L 200000
const long long MOD = 1000000007;
char S[MAX_L+1];
long long D[MAX_L + 1];
Trie t;

int solve(){
    int L = strlen(S);
    D[0] = 1;
    for(int i=1;i<=L;++i){
        for(int j=0;j<min(i, 305);++j){
            Trie *tt = t.find(S + j, i - j);
            if (tt != NULL) D[i] += (D[j] * tt->count);
            D[i] %= MOD;
        }
    }
    return D[L];
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> S;
        t.insert(S);
    }
    cin >> S;
    cout << solve() << '\n';
    return 0;
}