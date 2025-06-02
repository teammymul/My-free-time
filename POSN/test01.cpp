#include <bits/stdc++.h>
using namespace std;

int main(){
	int a; 
	for(int i = 0 ; i < 3 ; i++){
		cin >> a;
		if (i == 0){
			if (a < 5){
				cout << "fail";
				return 0;
			}
		}
		if (i == 1)
			if ( a < 20){
				cout << "fail";
				return 0;
			}
			if ( i == 2){
				if( a < 25){
					cout << "fail";
					return 0;
				}
			}
	}
	cout << "pass";
	return 0;
}