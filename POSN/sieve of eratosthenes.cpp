#include<bits/stdc++.h>
using namespace std;
bool checker[1000000000];
void primenumber(int n ){
	// bool checker[n];
	// memset(checker, true, sizeof(checker));
	for(int p = 2 ; p*p <= n ; p++){
		if(!checker[p]){
			for(int j = p*p ; j <= n; j +=p){
				checker[j] = true;
			}
		}
	}
	for (int i = 2 ; i <= n ; i++){
		if(!checker[i]){
			cout << i <<" ";
		}
	}
}
int main(){
	int n ;
	cin >> n;
	primenumber(n);
}