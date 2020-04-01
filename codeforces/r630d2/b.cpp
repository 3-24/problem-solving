#include <bits/stdc++.h>
using namespace std;

int arr[1000];
int solve(){
	int n;
	int color[1000];
	memset(color,0,sizeof(int)*1000);
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> arr[i];
	}
	int m = 0;
	for (int i=0;i<n;i++){
		int isColored = 0;
		for (int j=0;j<i;j++){
			if (__gcd(arr[i], arr[j]) > 1){
				color[i] = color[j];
				isColored = 1;
				break;
			}
		}
		if (!isColored){
			m++;
			color[i] = m;
		}
	}

	cout << m << "\n";
	for (int i=0;i<n;i++){
		cout << color[i] << " ";
	}
	cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
	cin >> t;
    while (t--) solve();
    return 0;
}
