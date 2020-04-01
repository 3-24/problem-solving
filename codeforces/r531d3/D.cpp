#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; // length of s, <= 3*10^5
    string s;
    cin >> n;
    cin >> s;
    int countChar[3] = {-n/3,-n/3,-n/3};

    for (int i=0;i<n;i++){
        countChar[int(s[i]) - int('0')] += 1;
    }

    if (countChar[0] < 0){
        for (int i=0;i<n;i++){
            int num = int(s[i])-int('0');
            if (num != 0 && countChar[num] > 0){
                countChar[num]--;
                countChar[0]++;
                s[i] = '0';
                if (countChar[0] == 0) break;
            }
        }
    }

    if (countChar[2] < 0 ){
        for (int i=n-1;i>=0;i--){
            int num = int(s[i])-int('0');
            if (num != 2 && countChar[num] > 0){
                countChar[num]--;
                countChar[2]++;
                s[i] = '2';
                if (countChar[2] == 0) break;
            }
        }
    }

    if (countChar[1] < 0){
        if ( countChar[2] > 0){
            for (int i=0;i<n;i++){
                if (s[i] == '2'){
                    s[i] = '1';
                    countChar[2]--;
                    countChar[1]++;
                    if (countChar[2] == 0) break;
                }
            }
        }

        for (int i=n-1;i>=0;i--){
            if (countChar[1] == 0) break;
            if (s[i] == '0') {
                s[i] = '1';
                countChar[0]--;
                countChar[1]++;
            }
            if (countChar[1] == 0) break;
        }
    }

    cout << s;

    return 0;
}