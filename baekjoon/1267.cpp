#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int fee1 = 0, fee2 = 0;
    while (n--)
    {
        int x;
        cin >> x;
        fee1 += (x / 30 + 1) * 10;
        fee2 += (x / 60 + 1) * 15;
    }

    if (fee1 < fee2){
        cout << 'Y' << ' ' << fee1;
    } else if (fee1 == fee2){
        cout << 'Y' <<  ' ' << 'M' << ' ' << fee1;
    } else {
        cout << 'M' << ' '<< fee2;
    }
    return 0;
}