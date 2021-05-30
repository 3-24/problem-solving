#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()

template <typename T>
bool exist_vector(vector<T> v, T x){    // unsorted
    return (find(v.begin(), v.end(), x) != v.end()) ? true : false;
}


void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<char> count;
    char prev_char = 'x';
    for (auto &c: s){
        if (exist_vector<char>(count, c)){
            if (prev_char != c){
                cout << "NO\n";
                return;
            };
        } else {
            count.push_back(c);
        }

        prev_char = c;
    }
    cout << "YES\n";
    return;
}

int main(){
    faster
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}