#include <bits/stdc++.h>

using namespace std;

bool isLeapYear(int year){
	if (year % 4 == 0){
		if (year % 100 == 0){
			return year % 400 == 0 ? true : false;
		}
		else return true;
	}
	else return false;
}

int main(){
	int year;
	cin >> year;
	cout << isLeapYear(year) ? 1 : 0 ;
}
