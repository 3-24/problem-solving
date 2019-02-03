#include <bits/stdc++.h>
using namespace std;

int countRound(int a, int b){
    if (a>b) swap(a,b);
    if (a % 2 && a+1 == b) return 1;
    return countRound((a+1)/2,(b+1)/2)+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numParticipants, a, b;
    cin >> numParticipants >> a >> b;
    cout << countRound(a,b);
    return 0;
}