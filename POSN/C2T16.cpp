#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    long long int d[n];
    for(int i = 0 ; i < n ; ++i){
        cin>>d[i];
    }
    for(int i = 0 ; i < n ; ++i){
        long long int crr = d[i];
        int L = i-1;
        int R = i+1;
        while (true)
        {
            bool LM = false;
            bool RM = false;
            if(crr > d[L] && L > -1){
                LM = true;
                crr+=d[L];
                L--;
            }
            if(crr > d[R] && R < n){
                RM = true;
                crr+=d[R];
                R++;
            }
            if(!LM && !RM){
                break;
            }
        }
        cout<<crr<<" ";
    }
}