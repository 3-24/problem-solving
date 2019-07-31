#include <bits/stdc++.h>

using namespace std;

void coutRepeat(char c, int l){
    for (int i=0;i<l;i++){
        cout << c;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        coutRepeat(' ', n-i-1);
        coutRepeat('*', i*2+1);
        cout << endl;
    }
    return 0;
}