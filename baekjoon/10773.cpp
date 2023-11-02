#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int k;
    cin >> k;
    int x;
    stack<int> st;
    ll sum = 0;
    for (int i=0; i<k; i++){
        cin >> x;
        if (x != 0){
            st.push(x);
            sum += x;
        } else {
            int y = st.top();
            sum -= y;
            st.pop();
        }
    }

    cout << sum;
    return 0;
}