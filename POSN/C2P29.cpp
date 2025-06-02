#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    map<int,vector<int>> mp;
    vector<int> in(n+1,0);
    vector<int> out(n+1,0);
    for(int i = 1 ; i <= m ; ++i){
        int a,b;cin>>a>>b;
        mp[a].push_back(b);
        in[b]++;
        out[a]++;
    }
    queue<pair<int,int>> pq;
    int s = 1;
    pq.push({s,1});
    map<int, vector<int>> level_map;
    while(!pq.empty()){
        auto[crr,s] = pq.front();
        pq.pop();
        level_map[crr].push_back(s);
        for(int i = 0 ; i < mp[s].size(); ++i){
            pq.push({mp[s][i],crr+1});
        }
    }
    for (auto &[level, nodes] : mp) {
        cout<<level;
        if(nodes.empty()){
            cout<<endl;
            continue;
        }
        else cout<<"->";
        for(int i = 0 ; i < nodes.size();++i){
            cout<<nodes[i];
            if(i != nodes.size()-1) cout<<"->";
        }
        cout<<endl;
    }
    for(int i = 1 ; i <= n ; ++i){
        cout<<in[i]<<" "<<out[i]<<endl;
    }
}