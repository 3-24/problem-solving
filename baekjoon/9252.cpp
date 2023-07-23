#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int last_index1[128], last_index2[128];
int dp[1001][1001];
// 0: increment first, 1: increment second, 2: increment both
short decision[1001][1001];

int step(int i, int j){
    if (i >= s1.length() || j >= s2.length()) return 0;
    if (dp[i][j] == 0){
        if (s1[i] == s2[j]){
            decision[i][j] = 2;
            dp[i][j] = step(i+1, j+1) + 1;
        } else {
            char c1= s1[i];
            char c2 = s2[j];
            if (j > last_index2[c1]){
                decision[i][j] = 0;
                dp[i][j] = step(i+1, j);
            }
            else if (i > last_index1[c2]){
                decision[i][j] = 1;
                dp[i][j] = step(i, j+1);
            }
            else {
                int x = step(i+1, j);
                int y = step(i, j+1);
                decision[i][j] = (x > y) ? 0 : 1;
                dp[i][j] = max(x, y);
            }
        }
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s1 >> s2;

    memset(last_index1, -1, sizeof(last_index1));
    memset(last_index2, -1, sizeof(last_index2));
    for (int i=0; i<s1.length(); i++){
        char c = s1[i];
        last_index1[c] = max(last_index1[c], i);
    }
    for (int i=0; i<s2.length(); i++){
        char c = s2[i];
        last_index2[c] = max(last_index2[c], i);
    }

    int l = step(0, 0);
    cout << l << '\n';
    int i = 0, j = 0;
    while (i < s1.length() && j < s2.length()){
        if (decision[i][j] == 0){
            i += 1;
        } else if (decision[i][j] == 1){
            j += 1;
        } else {
            cout << s1[i];
            i += 1;
            j += 1;
        }
    }
    return 0;
}