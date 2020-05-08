#include <bits/stdc++.h>
using namespace std;

int count_word_occurence(string document, string word, int index){
    int first_index = document.find(word, index);
    if (first_index == string::npos) return 0;
    else return 1+ count_word_occurence(document, word, first_index+word.length());
}

int main(){
    string document;
    getline(cin, document);
    string word;
    getline(cin, word);
    cout << count_word_occurence(document, word, 0);
    return 0;
}