#include <bits/stdc++.h>
using namespace std;
int main(){
	int i;
	vector<char> v;
	string a;
	cin >> a;
	int n = a.size();
	v.push_back(a[0]);
	for(i = 1 ; i < n ; i++){
		bool check = false;
		for(int j = 0 ; j< v.size(); j++){
			if(v[j] >= a[i]){
				v[j] = a[i];
				check = true;
				break;
			}
		}
		if (!check){
			v.push_back(a[i]);
		}
	}
	cout << v.size();
	return 0;
}
