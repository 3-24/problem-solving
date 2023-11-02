#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    deque<int> s;
    int n;
    cin >> n;
    while (n--){
        int op;
        cin >> op;
        if (op == 0){
            if (s.empty()) cout << "0\n";
            else {
                int x = s.front();
                s.pop_front();
                cout << x << '\n';
            }
        }
        else {
            auto it = lower_bound(s.begin(), s.end(), op);
            s.insert(it, op);
        }
    }
    return 0;
}