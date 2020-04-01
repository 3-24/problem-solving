#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int A[n], B[n];

	for (int i=0;i<n;i++){
		cin >> A[i];
	}
	for (int i=0;i<n;i++){
		cin >> B[i];
	}

	int sum = 0;
	sort(A,A+n);
	sort(B,B+n);

	for (int i=0;i<n;i++){
		sum += A[i] * B[n-1-i];
	}

	cout << sum;
	return 0;
}
