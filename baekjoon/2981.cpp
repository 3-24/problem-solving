#include <bits/stdc++.h>
using namespace std;

vector<int> diff(vector<int> V, int l){
    vector<int> U;
    for (int i=0;i<l;i++){
        U.push_back(abs(V[(i+1)%l]-V[i]));
    }
    return U;
}

int gcd(int a, int b){
    if (a<b) swap(a,b);
    if (b == 0) return a;
    int r = a % b;
    return (gcd(b,r));

}

int gcdVector(vector<int> V, int l){
    int d = 0;
    for (int i=0;i<l;i++){
        d = gcd(d,V[i]);
    }
    return d;
}

void printSubmultiple(int d){
    stack<int> Q;
    int m;
    for (m = 2; m<= (int)sqrt((double)d); m++){
        if (!(d % m)){
            cout << m << ' ';
            Q.push(d/m);
        }
    }
    m--;
    if ( m * m == d ) Q.pop();
    while(!Q.empty()){
        cout << Q.top() << ' ';
        Q.pop();
    }
    cout << d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> A;
    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    vector <int> B = diff(A,n);
    int d = gcdVector(B,n);
    printSubmultiple(d);
    return 0;
}