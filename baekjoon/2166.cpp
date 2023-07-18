#include <bits/stdc++.h>

using namespace std;

int n;
long long int point[10000][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> point[i][0] >> point[i][1];
    }
    
    long long int s = 0;

    // Gauss polygon area formula
    for (int i=0; i<n; i++){
        int j = (i + 1) % n;
        s += point[i][0] * point[j][1] - point[i][1] * point[j][0];
    }

    s = abs(s);

    double area = (double)s / 2;

    long long int i = (long long int) (area * 10 + 0.5);

    cout << std::fixed << std::setprecision(1) << (double)i /10;

    return 0;
}