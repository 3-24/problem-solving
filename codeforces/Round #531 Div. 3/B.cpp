#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; // length of array, number of colors
    cin >> n >> k;
    int A[n];
    int elementSize[5001] = {0,}, resultColoring[n], colorCount[k+1] = {0,}, maxElementSize = 0;
    vector<int> colorMap[k + 1];

    for (int i = 0; i < n; i++) {
        cin >> A[i]; // <= 5000

        elementSize[A[i]] += 1;

        if (elementSize[A[i]] > k) {
            cout << "NO";
            return 0;
        }

        if (maxElementSize < elementSize[A[i]]) maxElementSize = elementSize[A[i]];

        int color = elementSize[A[i]];
        resultColoring[i] = color;
        colorCount[color] += 1;
        colorMap[color].push_back(i);
    }

    cout << "YES" << endl;
    if (maxElementSize < k) {
        for (int c = 1; c <= k; c++) {
            while (colorCount[c] > 1) {
                maxElementSize += 1;
                colorCount[c]--;
                int location = colorMap[c].back();
                colorMap[c].pop_back();
                resultColoring[location] = maxElementSize;
                if (maxElementSize == k){
                    for (int i=0;i<n;i++){
                        cout << resultColoring[i];
                        if (i != n-1){
                            cout << ' ';
                        }

                    }
                    return 0;
                }
            }
        }
    }
    else{
        for (int i=0;i<n;i++){
            cout << resultColoring[i];
            if (i != n-1){
                cout << ' ';
            }

        }
        return 0;
    }
}