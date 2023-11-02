#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int n,m;
ll sum = 0;

vector<ll> A;

void hapchae(){
	sum += A[0] + A[1];
	ll temp;
	temp = A[0]+A[1];
	A[0] = temp;
	A[1] = temp;
	sort(A.begin(),A.end());
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int t;

	for (int i=0;i<n;i++){
		cin >> t;
		sum += t;
		A.push_back(t);
	}

	sort(A.begin(),A.end());

	while(m--){
		hapchae();
	}

	cout << sum;

	return 0;

}

