#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template <typename T>
bool exist_vector(vector<T> v, T x){return (find(v.begin(), v.end(), x) != v.end()) ? true : false;} // unsorted

void solve(){
    ll n;
    cin >> n;
    ll digit = 1;
    ll sum = 0;
    int count = 0;
    while (true){
        sum += digit;
        for (int i=1;i<=9;i++){
            if (sum*i <= n){
                count++;           
            } else {
                cout << count << endl;
                return;
            }
        }
        digit *= 10;
    }
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