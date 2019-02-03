#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l;
    cin >> n >> l;
    int realLength, al;
    bool lengthIsValid = false;
    for (realLength=l;realLength<=100;realLength++){
        al = n - (realLength-1)*realLength/2;
        if (!(al % realLength)){
            lengthIsValid = true;
            break;
        }
    }
    if (!lengthIsValid || al < 0) cout << -1;
    else{
        int a = al / realLength;
        for (int i=0;i<realLength;i++){
            cout << a+i << ' ';
        }
    }
    return 0;
}