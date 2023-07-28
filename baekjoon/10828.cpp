#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    stack<int> st;
    while (N--){
        string s;
        cin >> s;
        if (s == "push"){
            int x;
            cin >> x;
            st.push(x);
        } else if (s == "top"){
            if (st.empty()) {
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
            }
        } else if (s == "size"){
            cout << st.size() << '\n';
        } else if (s == "pop"){
            if (st.empty()){
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if (s == "empty") {
            cout << (st.empty()) << '\n';
        } else assert(false);
    }
    return 0;
}