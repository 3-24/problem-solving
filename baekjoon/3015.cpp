#include <bits/stdc++.h>

//   _________    _____|__| ______
//  /  _ \__  \  /  ___/  |/  ___/
// (  <_> ) __ \_\___ \|  |\___ \ 
//  \____(____  /____  >__/____  >
//            \/     \/        \/ 

using namespace std;

vector<pair<int, int>> st;
long long cnt = 0;

void foo(int x){
    if (st.empty()){
            st.push_back({x, 1});
            return;
    }
     if (x < st.back().first){
        cnt += 1;
        st.push_back({x, 1});
        return;
    } else if (x == st.back().first){
        cnt += st.back().second;
        if (st.size() >= 2) cnt += 1;
        st.back().second += 1;
        return;
    } else {
        cnt += st.back().second;
        st.pop_back();
        foo(x);
    }   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--){
        int x;
        cin >> x;
        foo(x);
    }
    cout << cnt;
}