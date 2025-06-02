#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans;cin>>ans;
    while(ans--){
        int n,m,s,t;
        cin>>n>>m>>s>>t;
        map<int,vector<pair<int,int>>> mp;
        vector<int> dist(20005,INT_MAX);
        for(int i = 0 ; i < m ; ++i){
            int st,e,w;cin>>st>>e>>w;
            mp[st].push_back({w,e});
            mp[e].push_back({w,st});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[s] = 0;
        pq.push({0,s});
        while (!pq.empty())
        {
            auto[crr,st]  = pq.top();
            pq.pop();
            for(auto[w,v] : mp[st]){
                if(dist[v] > crr+w){
                    dist[v] = crr+w;
                    pq.push({crr+w,v});
                }
                else continue;
                }
            }
        if(dist[t] == INT_MAX) {
            cout<<"unreachable"<<endl;
            continue;
        }
        cout<<dist[t]<<endl;
        }
}