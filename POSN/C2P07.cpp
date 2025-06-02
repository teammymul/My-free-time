#include <bits/stdc++.h>
using namespace std;
double distance (int a , int b){
	int d;
	d = sqrt(pow(a,2)+pow(b,2));
	return d;
}
int main(){
	int n ; cin >> n;
	vector<tuple<int,int,int,int>> q;
	for(int i = 0 ; i < n ; ++i){
		int a,b;
		cin >> a >> b;
		double d;
		d = distance(a,b);
		q.push_back({d,i,a,b});
	}
	sort(q.begin(),q.end());
	int cnt = q.size();
	for(int i = 0 ; i < cnt ; i ++){
		int a,b,c,d;
		tie(a,b,c,d) = q[i];
		cout << "("<<c <<","<<" "<<d<<")"<<endl;
	}
}