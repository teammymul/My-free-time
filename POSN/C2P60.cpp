#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
vector<long long int> dp(10005,-1);
long long int end(int n){
    if(n==0) return 1;
    if(dp[n] != -1) return dp[n];
    long long int ans = 1;
    for(int i = n-1 ; i >= 0 ; --i){
        if(v[i] < v[n]){
           ans = max(ans,1+end(i)); 
           dp[n] = ans;
        }
    }
    return ans;
}
void lis(){
    long long int  result = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = v.size()-1 ; i >=0 ; --i){
        result = max(result,end(i));
    }
    cout<<result;
}
int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    lis();
}