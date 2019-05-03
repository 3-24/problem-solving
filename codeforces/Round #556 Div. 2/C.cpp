#include <bits/stdc++.h>
#include <string.h>
using namespace std;


int n,n1=0,n2=0,count_print = 0;

void print_element(int m){
    count_print++;
    (m == 1) ? n1-- : n2--;
    (count_print == n) ? cout << m : cout << m << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int temp;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> temp;
        temp == 1 ? n1++ : n2++;
    }
    if (n2 != 0){
        print_element(2);
    }

    if (n1 != 0){
        print_element(1);
    }

    while (n2 != 0){
        print_element(2);
    }

    while(n1 != 0){
        print_element(1);
    }

    return 0;
}