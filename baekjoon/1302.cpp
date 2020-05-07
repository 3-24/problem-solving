#include <bits/stdc++.h>

using namespace std;

vector<string> selled_count[1001];

int main(){
    int n;
    map<string, int> books;
    cin >> n;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        if (books.find(s) == books.end()){
            books.insert( pair<string,int>(s,1) );
        }
        else books.find(s)->second++;
    }

    map<string,int>::iterator it;

    int count_max = 0;
    for (it = books.begin();it != books.end(); it++){
        selled_count[it->second].push_back(it->first);
        if (it->second > count_max) count_max = it->second;
    }

    if (count_max > 0){
        vector<string> max_books = selled_count[count_max];
        sort(max_books.begin(), max_books.end());
        cout << *max_books.begin();
    }
    return 0;
}