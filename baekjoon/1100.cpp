#include <bits/stdc++.h>
using namespace std;

int main(){
    int count = 0;
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            char s;
            cin >> s;
            if (s == 'F' && !(i+j & 1)){
                count++;
            }
        }
    }
    cout << count;
    return 0;
}