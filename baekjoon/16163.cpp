#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<char> s;

int main(){
    string tmp;
    cin >> tmp;
    for (int i=0; i<tmp.length(); i++){
        s.push_back('@');
        s.push_back(tmp[i]);
    }
    s.push_back('@');

    int n = s.size();
    vector<int> max_palindrome_radius(n, 0);

    int max_index = 0;
    int max_value = 0;

    for (int i=1; i<n; i++){
        int r = 0;
        if (max_value > i){
            int i_mirror = max_index - (i - max_index);
            r = min(max_palindrome_radius[i_mirror], max_value - i);
        }
        while (true){
            int new_r = r + 1;
            if (i - new_r >= 0 && i + new_r < n && s[i-new_r] == s[i+new_r]){
                r = new_r;
            } else break;
        }
        max_palindrome_radius[i] = r;

        if (max_value < i + r){
            max_value = i + r;
            max_index = i;
        }
    }

    ll ret = 0;
    for (int i=0; i<n; i++){
        ll r = max_palindrome_radius[i];
        if (i & 1) ret += ((r+2) >> 1);
        else ret += ((r+1) >> 1);
    }

    cout << ret << '\n';
    return 0;
}