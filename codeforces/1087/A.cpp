#include <string>
#include <iostream>
using namespace std;

int main(){
    string T;
    getline(cin,T);
    int l = T.length(), count = 0, i = (l+1)/2, sign = 0;
    while (count<l){
        count++;
        cout << T[i-1];
        (!(sign % 2)) ? i += count : i-=count;
        sign++;
    }
    return 0;
}