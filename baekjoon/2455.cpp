#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numPassengers = 0, numPassengersMax = 0;
    int getOff, getOn;
    for (int i=0;i<4;i++){
        cin >> getOff >> getOn;
        numPassengers = numPassengers -getOff + getOn;
        numPassengersMax = max(numPassengersMax, numPassengers);
    }
    cout << numPassengersMax;
    return 0;
}