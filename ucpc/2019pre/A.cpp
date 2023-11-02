#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int ANS[11] = {1,2,3,4,5,4,3,2};
    cin >> n;
    cout << ANS[(n-1)%8];
    return 0;
}