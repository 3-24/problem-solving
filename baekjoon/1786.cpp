#include <bits/stdc++.h>

using namespace std;

#define MAX_LENGTH 1000000

string T, P;
int arr[MAX_LENGTH];

int main(){
    getline(cin, T);
    getline(cin, P);

    // KMP Algorithm
    const int tl = T.size();
    const int pl = P.size();

    // Init
    int i = 1;
    int j = 0;

    while (i < pl){
        if (P[i] == P[j]){
            arr[i] = j+1;
            i++;
            j++;
        } else {
            if (j > 0) j = arr[j-1];
            else {
                arr[j] = 0;
                i++;
            }
        }
    }


    i = 0;
    j = 0;

    // KMP
    vector<int> res;

    while (i < tl){
        if (T[i] == P[j]){
            if (j == pl - 1){
                int r = i - j;
                res.push_back(r);
                if (j > 0) j = arr[j-1];
                else i++;
            } else {
                i++;
                j++;
            }
        } else {
            if (j > 0) j = arr[j-1];
            else i++;
        }
    }

    cout << res.size() << '\n';
    for (int r: res){
        cout << r+1 << '\n';
    }

    return 0;
}