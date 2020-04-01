#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a<b) swap(a,b);
    if (b == 0) return a;
    int r = a % b;
    return gcd(b,r);
}

void printRotation(int primary, int secondary){
    int d = gcd(primary, secondary);
    cout << primary/d << '/' << secondary/d << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int standard, beCompared;
    cin >> standard;
    n--;
    while(n--){
        cin >> beCompared;
        printRotation(standard,beCompared);
    }
    return 0;
}