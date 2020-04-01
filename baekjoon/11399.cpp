#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;
int P[MAX_N+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    sort(P, P + n);

    int time_total = 0;
    for (int i = 0; i < n; i++) {
        time_total += (n - i) * P[i];
    }
    cout << time_total << endl;
    return 0;
}