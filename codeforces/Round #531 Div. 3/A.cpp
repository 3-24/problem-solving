#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, resultArr[4] = {0,1,1,0};
    cin >> n;
    cout << resultArr[n%4];
    return 0;
}