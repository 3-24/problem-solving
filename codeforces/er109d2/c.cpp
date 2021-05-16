#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()



vector<ll> solve(vector<pair<ll, int>> x, ll m){
    vector<int> s;
    vector<ll> result(x.size(), -1);

    for (int i=0;i<x.size();i++){
        ll loc = x[i].first;
        if (loc < 0){
            if (s.empty()){
                s.push_back(i);
            }
            else{
                int j = s.back();
                s.pop_back();
                result[i] = (-loc - x[j].first) / 2;
                result[j] = (-loc - x[j].first) / 2;
            }
        }
        else s.push_back(i);
    }

    while (s.size() >= 2){
        int i = s.back(); s.pop_back();
        ll loc1 = x[i].first;       // dir 'R'
        int j = s.back(); s.pop_back();
        ll loc2 = x[j].first;

        result[i] = m - (loc1+loc2) / 2;
        result[j] = m - (loc1+loc2) / 2;
    }

    return result;
}

bool compareTwos(pair<ll, int> a, pair<ll, int> b){
    return (abs(a.first) < abs(b.first));
}

int main(){
    ll t;
    cin >> t;
    while (t--){
        ll n,m;
        cin >> n >> m;
        ll x[n+2];
        for (int i=0;i<n;i++){
            cin >> x[i];
        }
        char dir[n+2];
        for (int i=0;i<n;i++){
            cin >> dir[i];
        }

        // Position and Original Index
        vector<pair<ll, int>> even;
        vector<pair<ll, int>> odd;

        for (int i=0;i<n;i++){
            ll takeInv;
            if (dir[i] == 'R') takeInv = 1;
            else takeInv = -1;

            if (x[i] % 2 == 0) even.push_back(make_pair(takeInv * x[i], i));
            else odd.push_back(make_pair(takeInv * x[i], i));
        }

        sort(even.begin(), even.end(), compareTwos);
        sort(odd.begin(), odd.end(), compareTwos);

        // Array of time results
        vector<ll> even_result = solve(even, m);
        vector<ll>  odd_result = solve(odd, m);

        ll result[n+2];

        for (int i=0;i<even.size();i++){
            result[even[i].second] = even_result[i];
        }

        
        for (int i=0;i<odd.size();i++){
            result[odd[i].second] = odd_result[i];
        }

        for (int i=0; i<n; i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}