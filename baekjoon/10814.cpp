#include <bits/stdc++.h>

using namespace std;

struct Member{
    char name[101];
    int age;
    int index;
};

bool compare_member(struct Member a, struct Member b){
    if (a.age != b.age) return b.age > a.age;
    return b.index > a.index;
}


struct Member Members[100001];

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> Members[i].age >> Members[i].name;
        Members[i].index = i;
    }
    sort(Members,Members+n,compare_member);
    for (int i=0;i<n;i++){
        cout << Members[i].age << ' ' << Members[i].name << '\n';
    }
    return 0;
}