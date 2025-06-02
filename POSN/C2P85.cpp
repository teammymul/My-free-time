#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<long long int> dp(95,-1);
long long int all(int a){
    if(dp[a] != -1){
        return dp[a];
    }
    if(a < m && a >= 0){
        dp[a] = 1;
        return 1;
    }
    if(a < 0 ){
        return 0;''
    }
    return dp[a];
}
int main(){
    cin>>n;
    while (n--)
    {
        int a;
        cin>>a;
        all(a);
        cout<<dp[a]<<endl;
    }
}