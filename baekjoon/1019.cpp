#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[10]={};

    int mult = 1;
    int add = 1;

    while (n != 0){
        int r = n % 10;
        n = n / 10;
        for (int i=0; i<r; i++){
            arr[i] += (n+1) * mult;
        }
        arr[r] += n * mult + add;
        add += r * mult;

        for (int i=r+1; i<10; i++){
            arr[i] += n * mult;
        }
        arr[0] -= mult;
        mult *= 10;
    }

    for (int i=0; i<10; i++){
        cout << arr[i] << ' ';
    }
}