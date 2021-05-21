#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int val;
        map<int, vector<int>> m;
        for (int j=0;j<n;j++){
            cin >> val;
            if (m.find(val) == m.end()){
                m.insert(make_pair(val, vector<int>()));
            }
            m.find(val)->second.push_back(j);
        }

        ll result = 0;
        for (const auto &p: m){
            ll psum = 0;
            for (auto &it: p.second){
                result = result + psum * (n-it);
                psum += it+1;
            }
        }
        cout << result << endl;
    }
    return 0;
}