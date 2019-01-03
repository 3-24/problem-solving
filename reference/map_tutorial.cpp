#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> m;

    m.insert(make_pair("a",1));
    m.insert(make_pair("b",2));
    m.insert(make_pair("c",3));
    m["f"] = 4;

    m.erase("c");
    m.erase("f");

}