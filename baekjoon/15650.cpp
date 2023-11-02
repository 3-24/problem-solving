#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

list<list<int>> solve(int start, int end, int length){
    list<list<int>> v;
    if (length > end - start) return v;
    if (length == 0){
        v.push_back(list<int>{});
        return v;
    }

    for (auto i: solve(start+1, end, length-1)){
        list<int> elem = i;
        elem.push_front(start);
        v.push_back(elem);
    }

    for (auto i: solve(start+1, end, length)){
        v.push_back(i);
    }
    return v;
}

int main(){
    int n,m;
    cin >> n >> m;
    auto s = solve(1, n+1, m);
    for (auto i: s){
        for (auto j: i){
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}