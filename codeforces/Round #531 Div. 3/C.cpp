#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y;
    cin >> n >> x >> y;
    int durability, count = 0;
    for (int i=0;i<n;i++){
        cin >> durability;
        if (x >= durability) count++ ;
    }
    cout << (x>y ? n : (count+1)/2);
    return 0;
}