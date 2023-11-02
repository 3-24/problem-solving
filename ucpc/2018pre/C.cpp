#include <bits/stdc++.h>
using namespace std;

int d = 1000000007;
int countedList[3001];

int modInverse(int a, int m);

int modAdd(int a, int b){
    return (a+b)%d;
}

int modMult(int a, int b){
    long long int res = a;
    res *= b;
    res %= d;
    return (int)res;
}

int modDiv(int a, int b){
    return modMult(a, modInverse(b, d));
}

int modFactorial(int n){
    int r = 1;
    for (int i=1; i<=n; i++){
        r = modMult(r, i);
    }
    return r;
}

int countBlock(int l){
    if (countedList[l] != -1) return countedList[l];

    int count = 0;
    int l1 = 1, l2= l -l1;

    while (l1 < l){
        count = modAdd(count, modMult(countBlock(l1), countBlock(l2)));
        l1 += 2;
        l2 -= 2;
    }
    countedList[l] = count;
    ;
    return count;

}

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // countedList init
    memset(countedList,-1,sizeof(countedList));
    countedList[0] = 1;
    countedList[1] = 1;

    int l,n,A[3001] = {0,},m,B[3001]={0,};
    cin >> l >> n;

    A[0] = 1;
    B[0] = 1;

    int size = 0;

    for (int i=0;i<n;i++){
        int input;
        cin >> input;
        size += input;
        A[size] = 1;
    }

    cin >> m;

    size = 0;

    for (int i=0;i<m;i++){
        int input;
        cin >> input;
        size += input;
        B[size] = 1;
    }

    int number_of_operations = 0;
    int way_of_operations = 1;
    int prev_common_split = 0;
    long long int change_order = 1;
    long long int length_sum = 0;
    int length;

    for (int i=1;i<=l;i++){
        if (A[i] != B[i]) number_of_operations++;
        else if (A[i] && B[i]){
            length = i - prev_common_split;
            length_sum += length-1;

            way_of_operations = modMult(way_of_operations, countBlock(length));
            change_order = modDiv(change_order, modFactorial(length-1));

            prev_common_split = i;
        }
    }

    change_order = modMult(change_order, modFactorial(length_sum));

    cout << number_of_operations << ' '<< modMult(change_order,way_of_operations);

    return 0;
}
