#include <bits/stdc++.h>

using namespace std;

int fest2017(int rank){
	if (rank == 0) return 0;
	else if (rank  <= 1) return  500;
	else if (rank < 4 ) return 300;
	else if (rank < 7) return 200;
	else if (rank < 11) return 50;
	else if (rank < 16) return 30;
	else if (rank < 22) return 10;
	else return 0;
}


int fest2018(int rank){
	if (rank == 0) return 0;
	else if (rank == 1) return 512;
	else if (rank < 4) return 256;
	else if (rank < 8) return 128;
	else if (rank < 16) return 64;
	else if (rank < 32) return 32;
	else return 0;
}


int main(){
	int T,a,b;
	cin >> T;
	while(T--){
		int prize;
		cin >> a >> b;
		prize = (fest2017(a) + fest2018(b)) * 10000;
		cout << prize << endl;
	}
	return 0;
}
