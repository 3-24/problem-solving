#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n,k;
    cin >> n  >> k;
    int x = INT_MAX;
    for (int r=1;r<k;r++){
        if (n % r == 0){
            int temp = (n/r)*k + r;
            if (temp < x){
                x = temp;
            }
        }
    }
    cout << x;
    return 0;
}