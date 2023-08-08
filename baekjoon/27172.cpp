#include <bits/stdc++.h>

using namespace std;

int N;
int score[100001];
int card[100001];
map<int, int> card_inv;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i=0; i<N; i++){
        cin >> card[i];
        card_inv[card[i]] = i;
    }

    for (int i=0; i<N; i++){
        for (int v=card[i]*2; v <=1000000; v+=card[i]){
            if (card_inv.contains(v)){
                score[i] += 1;
                score[card_inv[v]] -= 1;
            }
        }
    }
    for (int i=0; i<N; i++){
        cout << score[i] << ' ';
    }
}