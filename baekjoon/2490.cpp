#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char Yut[5] = {'D','C','B','A','E'};
    int input;
    for (int i=0;i<3;i++){
        int sum = 0;
        for (int j=0;j<4;j++){
            cin >> input;
            sum += input;
        }
        cout << Yut[sum] << endl;
    }
    return 0;
}