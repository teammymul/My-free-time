#include <bits/stdc++.h>
using namespace std;
int d[55][55][55];
void dfs(int i , int j , int k,int x , int y ,int z,bool (&vs)[55][55][55]){
    for(int ii = -1  ; ii <= 1 ; ++ii)
    {
    for(int jj = -1 ; jj <= 1 ; ++jj)
    {
    for(int kk= -1 ; kk <= 1 ; ++kk)
    {
        if(i+ii > x || i+ii < 0 || j+jj > y || j+jj < 0 || k+kk > z || k+kk < 0 ) continue;
        if(abs(ii) + abs(jj) + abs(kk) >= 2) continue;
        if(d[i+ii][j+jj][k+kk] == 1 && !vs[i+ii][j+jj][k+kk]){
            vs[i+ii][j+jj][k+kk] = true;
            dfs(i+ii,j+jj,k+kk,x,y,z,vs);
        }
}
}
}
}
void find(int x , int y , int z){
    int cnt = 0 ;
    bool vs[55][55][55] = {false};
    for(int i = 0 ; i < x ; ++i)
    {
    for(int j = 0 ; j < y ; ++j)
    {
    for(int k= 0 ; k < z ; ++k)
    {
        if(!vs[i][j][k]){
            vs[i][j][k] = true;
            if(d[i][j][k] == 1){
                dfs(i,j,k,x,y,z,vs);
                cnt++;
            }
        }
        else continue;
    }
    }
    }
    cout<<cnt<<endl;
}
void boom(int x, int y ,int z,int p ,int t , int q ,int r ){
    for(int i = -r ; i <=r ; ++i)
    {
    for(int j = -r ; j <=r ; ++j)
    {
    for(int k= -r ; k <=r ; ++k)
    {
        if(p+i > x || p+i < 0 || t+j > y || t+j < 0 || q+k > z || q+k < 0 ) continue;
        d[p+i][t+j][q+k] = 0;
}
}
}
}
int main(){
    int x,y,z;cin>>x>>y>>z;
    for(int i = 0 ; i < x ; ++i) for(int j = 0 ; j < y ; ++j) for(int k= 0 ; k < z ; ++k) cin>>d[i][j][k];
    find(x,y,z);
    int m;cin>>m;
    while (m--)
    {
        int p,t,q,r;cin>>p>>t>>q>>r;
        boom(x,y,z,p,t,q,r);
    }
    find(x,y,z);
}