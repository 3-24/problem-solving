#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int targetLength, stickLength = 64, count = 0;
    cin >> targetLength;
    while(targetLength){
        if (targetLength >= stickLength){
            targetLength -= stickLength;
            count++;
        }
        stickLength /= 2;
    }
    cout << count;
    return 0;
}