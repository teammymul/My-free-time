#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int data[n];
    int prevb;
    int cnt = 0;
    int mx;
    for(int i = 0 ; i < n ; ++i){
        int f,b;
        cin >> f >> b;
        data[i] = b;
    }
    for(int i = n-1 ; i >= 0 ; --i){
        if( i == n - 1 ) {
           prevb = data[i];
            continue;
        }
        if ( data[i]  <= prevb){
            cnt++;
        }
        else prevb = data[i];
    }
    cout << cnt;
    return 0;
}