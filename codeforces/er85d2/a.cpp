#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int moments=0, plays=0;
        bool success = true;
        while (n--){
            int a,b;
            cin >> a >> b;
            if (!(a-moments>=b-plays && moments <=a && plays <= b)){
                success = false;
            }
            moments = a;
            plays = b;
        }
        if (success) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
